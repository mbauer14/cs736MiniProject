#include "sharedMemory.h"

pthread_mutexattr_t mutex_shared_attr;
pthread_condattr_t cond_shared_attr;
pthread_mutex_t *lock;
pthread_cond_t *cond;
int *bufferFull;

int main(int argc, char **argv){

  int size = SIZE_512K;
  int returnVal;

  //create some shared memory here
  char* sharedMemory = (char *)mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
 
  lock = (pthread_mutex_t *)mmap(NULL, sizeof(pthread_mutex_t), PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  cond = (pthread_cond_t *)mmap(NULL, sizeof(pthread_cond_t), PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  bufferFull = (int *)mmap(NULL, sizeof(int), PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  *bufferFull = 0;

  if((returnVal = pthread_mutexattr_init(&mutex_shared_attr)) != 0){
    fprintf(stderr, "pthread_mutexattr_init");
    return 1;
  }
  if((returnVal = pthread_mutexattr_setpshared(&mutex_shared_attr, PTHREAD_PROCESS_SHARED)) != 0){
    fprintf(stderr, "pthread_mutexattr_setshared");
    return 1;
  }
  if((returnVal = pthread_mutex_init(lock, &mutex_shared_attr)) != 0){
    fprintf(stderr, "pthread_mutex_init");
    return 1;
  }

  if((returnVal = pthread_condattr_init(&cond_shared_attr)) != 0){
    fprintf(stderr, "pthread_condattr_init");
    return 1;
  }
  if((returnVal = pthread_condattr_setpshared(&cond_shared_attr, PTHREAD_PROCESS_SHARED)) != 0){
    fprintf(stderr, "pthread_condattr_setshared");
    return 1;
  }
  if((returnVal = pthread_cond_init(cond, &cond_shared_attr)) != 0){
    fprintf(stderr, "pthread_cond_init");
    return 1;
  }

  int pid;

  switch(pid = fork()){
  
    case 0:
      handleChild(&sharedMemory, size);
      break;
    case -1:
      perror("fork");
      break;
    default:
      handleParent(&sharedMemory, size);
      break;

  }


  return 0;
}

void handleChild(char **sharedMemory, int size){
  struct timespec start;
  if(clock_gettime(CLOCK_REALTIME, &start) == -1){
    perror("clock gettime");
    exit(EXIT_FAILURE);
  }
  printf("start seconds: %lu nanoseconds: %lu\n", start.tv_sec, start.tv_nsec);
  //this process will produce data
  pthread_mutex_lock(lock);
  while(*bufferFull == 1){
   pthread_cond_wait(cond, lock);
  }
  //produce data here
  void *data = malloc(size);
  memcpy(*sharedMemory, data, size);
  *bufferFull = 1; //buffer is now full
  printf("wrote %d bytes\n", size);
  pthread_cond_signal(cond);
  pthread_mutex_unlock(lock);
}

void handleParent(char **sharedMemory, int size){
  //this process will consume data
  pthread_mutex_lock(lock);
  while(*bufferFull == 0){
    pthread_cond_wait(cond, lock);
  }
  //consume the data here
  void *data = malloc(size);
  memcpy(data, *sharedMemory, size);
  *bufferFull = 0; //buffer is now empty
  printf("read: %d bytes\n", size);
  pthread_cond_signal(cond);
  pthread_mutex_unlock(lock);
  free(data);
  struct timespec stop;
  if(clock_gettime(CLOCK_REALTIME, &stop) == -1){
    perror("clock gettime");
    exit(EXIT_FAILURE);
  }
  printf("stop seconds: %lu nanoseconds: %lu\n", stop.tv_sec, stop.tv_nsec);
}

#include "runpipe.h"

int main(int argc, char **argv){

  int pid;
  int fd_to_child[2];
  int fd_to_parent[2];
  int size;

  if(argc < 2 || argc > 3){
    fprintf(stderr, "Usage: %s <buffersize>\n", argv[0]);
    exit(0);
  }
  else{
    size = atoi(argv[1]);
  }


  void *readbuffer = malloc(size);
  void *writebuffer = malloc(size);

  pipe(fd_to_child);
  pipe(fd_to_parent);


  switch(pid = fork()){

    case 0:
      handleChild(fd_to_child, fd_to_parent, size, &readbuffer);
      break;
    case -1:
      perror("fork");
      break;
    default:
      handleParent(fd_to_child, fd_to_parent, size, &writebuffer);
      break;
  }

  free(readbuffer);
  free(writebuffer);
  close(fd_to_child[0]);
  close(fd_to_child[1]);
  close(fd_to_parent[0]);
  close(fd_to_parent[1]);

  return 0;
}

void handleChild(int *fd_to_child, int *fd_to_parent, int size, void **readbuffer){
  
  //read in bytes
  int nbytes;
  struct timespec stop;
  nbytes = read(fd_to_child[0], *readbuffer, size);
  clock_gettime(CLOCK_REALTIME, &stop);
  write(fd_to_parent[1], &stop, sizeof(struct timespec));
}

void handleParent(int *fd_to_child, int *fd_to_parent, int size, void **writebuffer){
  //send whatever data is in the buffer, doesnt matter what it is
  struct timespec start;
  clock_gettime(CLOCK_REALTIME, &start);
  write(fd_to_child[1], *writebuffer, size);
  struct timespec stop;
  int bytes = read(fd_to_parent[0], &stop, sizeof(struct timespec));
  long startnano = (start.tv_sec * 1000000000) + start.tv_nsec;
  long stopnano = (stop.tv_sec * 1000000000) + stop.tv_nsec;
  printf("%lu\n", stopnano-startnano);
}

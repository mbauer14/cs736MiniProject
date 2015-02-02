#include "runpipe.h"

int main(int argc, char **argv){

  int pid;
  int fd[2];

  int size = SIZE_512K;

  pipe(fd);

  switch(pid = fork()){

    case 0:
      handleChild(fd, size);
      break;
    case -1:
      perror("fork");
      break;
    default:
      handleParent(fd, size);
      break;
  }

  return 0;
}

void handleChild(int* fd, int size){
  //child closes input side of pipe and writes output
  close(fd[0]);
  void *writebuffer = malloc(size);
  //send whatever data is in the buffer, doesnt matter what it is
  write(fd[1], writebuffer, size);
  free(writebuffer);
}

void handleParent(int* fd, int size){
  //parent closes the output side of the pip
  close(fd[1]);
  //read in bytes
  void *readbuffer = malloc(size);
  int nbytes;
  nbytes = read(fd[0], readbuffer, size);
  printf("bytes read: %d\n", nbytes);
  free(readbuffer);
}

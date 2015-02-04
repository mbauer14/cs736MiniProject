#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define SIZE_4 4
#define SIZE_16 16
#define SIZE_64 64
#define SIZE_256 256
#define SIZE_1K 1024
#define SIZE_4K 4096
#define SIZE_16K 16384
#define SIZE_64K 65536
#define SIZE_256K 262144
#define SIZE_512K 524288

void handleChild(int *fd_to_child, int *fd_to_parent, int size, void **readbuffer);

void handleParent(int *fd_to_child, int *fd_to_parent, int size, void **writebuffer);

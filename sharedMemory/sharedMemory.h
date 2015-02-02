#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <pthread.h>
#include <stdlib.h>

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


void handleChild(char **sharedMemory, int size);

void handleParent(char **sharedMemory, int size);

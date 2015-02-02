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

#define BILLION 1000000000L;

void handleChild(int* fd, int size);

void handleParent(int* fd, int size);

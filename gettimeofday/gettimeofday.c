#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{

	struct timeval start, end;

	gettimeofday(&start, NULL);

	sleep(10);

	gettimeofday(&end, NULL);

	printf("%ld\n", ((end.tv_sec * 1000000000 + 1000*end.tv_usec)- (start.tv_sec * 1000000000 + 1000*start.tv_usec)));

	return 0;
}

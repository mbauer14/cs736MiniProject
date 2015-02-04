#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>


#define NANO_IN_SEC 1000000000
#define TICS_PER_NANO 3.192639 

/* assembly code to read the TSC */
static inline uint64_t RDTSC()
{
  unsigned int hi, lo;
    __asm__ volatile("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}


void getTicksPerNano()
{


	//Hold the results of clock_gettime
	struct timespec time_start, time_stop;
	//Hold the results of rdtsc
	uint64_t rdtsc_start, rdtsc_stop;

	clock_gettime(CLOCK_MONOTONIC, &time_start);
	rdtsc_start = RDTSC();

	uint64_t i;
	//for (i=0; i<)


}

/* bind this process to a specific core (1) so timing is actually accurate 
 * Calculate the number of ticks per nanosecond to convert rdtsc values back to timing.
 * */
void setupRDTSC()
{
	unsigned long cpuMask;
	cpuMask = 2; // bind to cpu 1
	sched_setaffinity(0, sizeof(cpuMask), &cpuMask);
	//getTicksPerNano();	
}





int main(int argc, char **argv)
{
	int loopIntervals = 1000;
	uint64_t i;

	if (argc < 2) {
		printf("Didn't specify loop intervals, using default.\n");

	}
	else {
		loopIntervals = atoi(argv[1]);
	}
	
	//setupRDTSC();

	uint64_t rdtsc_start=0, rdtsc_stop=0;
	struct timespec cgt_start, cgt_stop;
	struct timeval tod_start, tod_stop;

	unsigned int rdtsc_start_hi, rdtsc_start_lo;
	unsigned int rdtsc_stop_hi, rdtsc_stop_lo;

    	//__asm__ volatile("rdtsc" : "=a" (rdtsc_start_lo), "=d" (rdtsc_start_hi));
	clock_gettime(CLOCK_REALTIME, &cgt_start);
	//gettimeofday(&tod_start, NULL);

	//waste time
	//for (i=0; i< loopIntervals; i++);
	//i = 0;


	//__asm__ volatile("rdtsc" : "=a" (rdtsc_stop_lo), "=d" (rdtsc_stop_hi));
	clock_gettime(CLOCK_REALTIME, &cgt_stop);
	//gettimeofday(&tod_stop, NULL);

	
    	//rdtsc_start = ((uint64_t)rdtsc_start_hi << 32) | rdtsc_start_lo;
    	//rdtsc_stop = ((uint64_t)rdtsc_stop_hi << 32) | rdtsc_stop_lo;
	//uint64_t rdtsc_diff = ((float)(rdtsc_stop - rdtsc_start)) / TICS_PER_NANO;
	long cgt_diff = (cgt_stop.tv_sec * 1000000000 + cgt_stop.tv_nsec)- (cgt_start.tv_sec * 1000000000 + cgt_start.tv_nsec);
	//long tod_diff = (tod_stop.tv_sec * 1000000000 + 1000*tod_stop.tv_usec)- (tod_start.tv_sec * 1000000000 + 1000*tod_start.tv_usec);

	//printf("rdtsc: %ld\n", rdtsc_diff);	
	printf("clock_gettime: %ld\n", cgt_diff);
	//printf("gettimeofday: %ld\n", tod_diff);
	


	return 0;
}

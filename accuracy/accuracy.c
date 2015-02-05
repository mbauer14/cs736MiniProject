#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <unistd.h>
#include <math.h>


#define NANO_IN_SEC 1000000000
#define NANO_PER_TICS 0.436 

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


float getMean(long * arr, int len)
{
    int i;
    long sum = 0;
    long min = arr[0];

    //Get sum/mean
    for (i=0; i<len; i++){
        sum += arr[i];
        if (arr[i] < min) min = arr[i];
    }

    float mean = sum / (float)len;
    printf("Mean: %.3f\n", mean);	
    printf("Min: %lu\n", min);	
    float sum1 = 0;
    for (i=0; i<len; i++) {
        sum1 += (arr[i] - mean) * (arr[i] - mean);
    }
    float variance = sum1 / len;
    float std_dev = sqrt(variance);
    printf("Standard Dev: %.3f\n\n", std_dev);	

}




int main(int argc, char **argv)
{
	

    int sleepSeconds = 10;
    int numIters = 10;
    uint64_t i;
    uint64_t j;

	if (argc < 3) {
		printf("Usage: %s sleepSeconds numIters\n", argv[0]);
        return;
	}
	else {
		sleepSeconds = atoi(argv[1]);
		numIters = atoi(argv[2]);
	}
	
	setupRDTSC();
	
    struct timeval tod_start, tod_stop;
    long tod_diff;
	long cgt_diff;
    long rdtsc_start, rdtsc_stop;
    float rdtsc_diff;
	struct timespec cgt_start, cgt_stop;

	unsigned int rdtsc_start_hi, rdtsc_start_lo;
	unsigned int rdtsc_stop_hi, rdtsc_stop_lo;

  
    long * tod_arr = (long*) malloc(sizeof(long) * numIters);
    long * cgt_arr = (long*) malloc(sizeof(long) * numIters);
    uint64_t * rdtsc_arr = (uint64_t*) malloc(sizeof(long) * numIters);


    for (i=0; i<numIters; i++)
    {     
        //Perform tod testing
        /////////////////////// TOD /////////////////////////

        gettimeofday(&tod_start, NULL);
        sleep(sleepSeconds); 
        gettimeofday(&tod_stop, NULL);

        tod_diff = (tod_stop.tv_sec * 1000000000 + 1000*tod_stop.tv_usec)- (tod_start.tv_sec * 1000000000 + 1000*tod_start.tv_usec);
        tod_arr[i] = tod_diff; 
        printf("gettimeofday: %ld\n", tod_diff);
        
        //////////////////// CLOCK GET TIME /////////////////


        clock_gettime(CLOCK_REALTIME, &cgt_start);
        
        sleep(sleepSeconds);

        clock_gettime(CLOCK_REALTIME, &cgt_stop);
        
        cgt_diff = (cgt_stop.tv_sec * 1000000000 + cgt_stop.tv_nsec)- (cgt_start.tv_sec * 1000000000 + cgt_start.tv_nsec);
        cgt_arr[i] = cgt_diff;

        //printf("clock_gettime: %ld\n", cgt_diff);


        ///////////////////// RDTSC /////////////////////////
            
        __asm__ volatile("rdtsc" : "=a" (rdtsc_start_lo), "=d" (rdtsc_start_hi));
        sleep(sleepSeconds);
        __asm__ volatile("rdtsc" : "=a" (rdtsc_stop_lo), "=d" (rdtsc_stop_hi));

        rdtsc_start = ((long)rdtsc_start_hi << 32) | rdtsc_start_lo;
        sleep(sleepSeconds);
        rdtsc_stop = ((long)rdtsc_stop_hi << 32) | rdtsc_stop_lo;
        
        rdtsc_diff = ((float)(rdtsc_stop - rdtsc_start)) * NANO_PER_TICS;
        rdtsc_arr[i] = rdtsc_diff;       
 
        printf("rdtsc seconds per tick: %.3f\n", rdtsc_diff);	
    }	

  
    printf("TIME OF DAY\n");
    getMean(tod_arr,  numIters);
    printf("CLOCK GET TIME\n");
    getMean(cgt_arr,  numIters);
    printf("RDTSC\n");
    getMean(rdtsc_arr,  numIters);


	return 0;
}

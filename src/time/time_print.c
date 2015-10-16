#include <stdio.h>
#include <sys/time.h>
#include "time_print.h"


static struct timeval start,end; 

void time_start(void)
{
	    gettimeofday(&start, NULL); 
}

void time_stop(void)
{
	    gettimeofday(&end, NULL);
}

void time_print(void)
{
	    long timeuse =1000000 * ( end.tv_sec - start.tv_sec ) + (end.tv_usec - start.tv_usec); 
		    printf("time=%f second\n", timeuse /1000000.0); 
//		    printf("time=%f second\n", timeuse); 
}


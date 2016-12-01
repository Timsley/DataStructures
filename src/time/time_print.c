#include <stdio.h>
#include <sys/time.h>
#include "time_print.h"

#define FUNC_EXEC_TIME	100000

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

void time_main_test(void)
{
    int i;

    time_start();

    for(i=0; i<FUNC_EXEC_TIME; i++)
    //timt_test();


    time_stop();
    time_print();
}

#include <stdio.h>
#include <typedef.h>
#include <stdlib.h>
#include <time.h>
#include "time_print.h"
#include "sort.h"

#define N 500

static int a[N] = {0};

void part1_rand(void)
{
	int i;
	for(i=0; i<N; i++)
		a[i]= rand()%N;
}

void part1_print(int a[], int len)
{
	int i=0;

	for(i=0; i<len; i++)
		printf("%d  ", a[i]);

	printf("\n");
}

void part1_find_the_max(int k)
{
	//int a[] = {3,4,9,7,4,8,1,2};
//	int a[] = {3,4,9,7,4,8,1,2,4,9,7,4,8,1,2};
	time_start();
//	part1_print(a, sizeof(a)/sizeof(int));
	sort_bubble(a, sizeof(a)/sizeof(int));
	time_stop();
	time_print();

        printf("The a[%d] is %d\n", N/2, a[N/2]);
//	part1_print(a, sizeof(a)/sizeof(int));
}

VOID part1_main_test(VOID)
{
	srand(time(0));
	part1_rand();

	part1_find_the_max(1);
	printf("part1_main_test\n");	
}


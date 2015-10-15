#include <stdio.h>
#include <typedef.h>
#include "sort.h"

void part1_print(int a[], int len)
{
	int i=0;

	for(i=0; i<len; i++)
		printf("%d  ", a[i]);

	printf("\n");
}

void part1_find_the_max(int k)
{
	int a[] = {3,4,9,7,4,8};

	part1_print(a, sizeof(a));
	sort_bubble(a, sizeof(a));
	part1_print(a, sizeof(a));
}

VOID part1_main_test(VOID)
{
	part1_find_the_max(1);
	printf("part1_main_test\n");	
}

#include <stdio.h>
#include "sort.h"


void sort_bubble(int a[], int len)
{
	int i=0, j=0;
	int temp=0;

	for(i=0; i<len; i++)
	{
		for(j=1; j<len; j++)
		{
			if(a[i] < a[j])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

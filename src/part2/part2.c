#include <stdio.h>
#include "sort.h"

void part2_ex_219(int a[], int len)
{
    int i=0;
    int tempNum = a[0];
    int tempMax = 1;
    int max = 0;
    int maxNum = 0;

    sort_bubble(a, len);
    
    for(i=0; i<len; i++)
    {
        printf("%d  ", a[i]);
        if(tempNum == a[i])
        {
            tempMax++;
        }
        else
        {
            if(tempMax > max)
            {
                max = tempMax;
                maxNum = a[i-1];
            }
            tempNum = a[i];
            tempMax = 1;
        }
    }

    printf("maxNum=%d       max=%d\n", maxNum, max);
	if(max>len/2)
		printf("found the maxNum=%d\n", maxNum);
	else
		printf("cannot found the maxNum\n");
}


void part2_main_test(void)
{
    int a[] = {3, 3, 4, 2, 4, 4, 2, 4};
    int len = sizeof(a)/sizeof(a[0]);

    part2_ex_219(a, len);
}

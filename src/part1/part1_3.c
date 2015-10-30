#include <stdio.h>

/*
    print positive integer
    such as : if input 123, then will print 123
*/
void printOut(int n)
{
    if(n >= 10)
    {
        printOut(n/10);
    }
    printf("%d", n%10);
}

/*
    print integer
    such as : if input -123, then will print -123
*/
void printOut2(int n)
{
    if(abs(n)>=10)
    {
        printOut2(n/10);
        printf("%d",abs(n%10));
    }
    else
        printf("%d", n%10);
}

void part1_3_main_test(void)
{
    printOut2(321);
}

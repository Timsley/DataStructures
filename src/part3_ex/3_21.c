#include <stdio.h>


#define MAX_LEN 10
#define STACK1 0
#define STACK2 1


static int array[MAX_LEN] = {0};
static int s1_index = 0;
static int s2_index = MAX_LEN-1;


/* if index is 0, push value into Stack1, if index is 1, push value into Stack2 */
void _stack_push(int index, int value)
{
    if(s1_index == s2_index+1)
    {
        printf("Array is full, cannot insert\n");
        return;
    }
    
    if(STACK1 == index)
    {
        array[s1_index++] = value;
    }
    else if(STACK2 == index)
    {
        array[s2_index--] = value;
    }
}

/* if index is 0, pop value from Stack1, if index is 1, pop value from Stack2 */
void _stack_pop(int index)
{
    if((STACK1 == index) && (s1_index != 0))
    {
        s1_index--;
    }
    else if((STACK2 == index) && (s2_index != MAX_LEN-1))
    {
        s2_index++;
    }
}

void _stack_traverse(int index)
{
    int i=0;
    
    if(STACK1 == index)
    {
        printf("Stack1 : ");
        for(i=s1_index-1; i>=0; i--)
            printf("%2d  ", array[i]);
    }
    else if(STACK2 == index)
    {
        printf("Stack2 : ");
        for(i=s2_index+1; i<MAX_LEN; i++)
            printf("%2d  ", array[i]);
    }
    printf("\n");
}

void ex_3_21(void)
{
    _stack_push(STACK1, 1);
    _stack_push(STACK1, 2);
    _stack_push(STACK1, 3);
    _stack_push(STACK1, 4);
    _stack_push(STACK1, 6);
    
    _stack_push(STACK2, 5);
    _stack_push(STACK2, 6);
    _stack_push(STACK2, 7);
    _stack_push(STACK2, 8);
    _stack_push(STACK2, 9);
    
    _stack_pop(STACK1);
    _stack_pop(STACK2);
    _stack_pop(STACK2);
    
    _stack_push(STACK1, 7);
    _stack_push(STACK2, 10);
    _stack_push(STACK2, 10);

    _stack_push(STACK2, 1);

    _stack_traverse(STACK1);
    _stack_traverse(STACK2);
}

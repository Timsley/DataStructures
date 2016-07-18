#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_stack.h"


STACK * array_stack_init(void)
{
    STACK * stack = (STACK *)malloc(sizeof(STACK));
    if(!stack)
    {
        printf("malloc stack failed\n");
        return NULL;
    }

    stack->array = (ElementType *)malloc(ARRAY_STACK_LEN * sizeof(ElementType));
    if(!stack->array)
    {
        printf("malloc stack->array failed\n");
        return NULL;
    }

    stack->stack_size = ARRAY_STACK_LEN;
    stack->top_of_stack = EMPTY_STACK_INDEX;

    return stack;
}

void array_stack_uninit(STACK * stack)
{
    if(NULL != stack)
    {
        free(stack->array);
        free(stack);
    }
}

bool array_stack_is_empty(STACK * stack)
{
    return stack->top_of_stack == EMPTY_STACK_INDEX;
}

void array_stack_make_empty(STACK * stack)
{
    stack->top_of_stack = EMPTY_STACK_INDEX;
}

bool array_stack_is_full(STACK * stack)
{
    return stack->top_of_stack == ARRAY_STACK_LEN-1;
}

void array_stack_push(STACK * stack, ElementType * value)
{
    if(array_stack_is_full(stack))
    {
        printf("The stack is full, cannot push element\n");
    }
    else
    {
        //printf("insert value:%d     len:%d\n", *value, stack->top_of_stack);
        memcpy(&stack->array[++stack->top_of_stack], value, sizeof(ElementType));
    }
}

ElementType array_stack_top(STACK * stack)
{
    if(array_stack_is_empty(stack))
    {
        printf("The stack is empty\n");
        return 0;
    }
    else
    {
        return stack->array[stack->top_of_stack];
    }
}

void array_stack_pop(STACK * stack)
{
    if(array_stack_is_empty(stack))
    {
        printf("The stack is empty\n");
    }
    else
    {
        stack->top_of_stack--;
    }
}

ElementType array_stack_top_and_pop(STACK * stack)
{
    if(array_stack_is_empty(stack))
    {
        printf("The stack is empty\n");
        return 0;
    }
    else
    {
        return stack->array[stack->top_of_stack--];
    }
}

int array_stack_traverse(STACK * stack)
{
    int size = 0;

    size = stack->top_of_stack;
    //printf("size=%d\n", size+1);
    
    while(size >= 0)
    {
        printf("element=%d\n", stack->array[size]);
        size--;
    }

    return 0;
}

void array_stack_main_test(void)
{
    int i = 0;
    STACK * stack = array_stack_init();

    for(i=1; i<=10; i++)
        array_stack_push(stack, &i);

    array_stack_traverse(stack);

    array_stack_pop(stack);
    array_stack_pop(stack);
    array_stack_pop(stack);
    
    array_stack_traverse(stack);
}

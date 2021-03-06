#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


STACK * stack_init(void)
{
    STACK * stack = (STACK *)malloc(sizeof(STACK));
    if(!stack)
    {
        printf("malloc fail\n");
        return NULL;
    }

    memset(stack, 0, sizeof(STACK));
    stack->next = NULL;

    return stack;
}

bool stack_is_empty(STACK * stack)
{
    return (stack->next == NULL);
}

ElemType stack_pop(STACK * stack)
{
    ElemType retValue;
    
    STACK_CHECK_FAIL(stack);

    STACK * temp = NULL;
    
    if(!stack_is_empty(stack))
    {
        temp = stack->next;
        stack->next = stack->next->next;
        retValue = temp->Element;
        free(temp);
    }
    else
    {
        printf("stack is empty\n");
        return 0;
    }

    return retValue;
}

int stack_push(STACK * stack, ElemType ele)
{
    STACK_CHECK_FAIL(stack);

    NODE * node = (NODE *)malloc(sizeof(NODE));

    //memcpy(&node->Element, ele, sizeof(ElemType));
    node->Element = ele;
    node->next = stack->next;
    stack->next = node;

    return STACK_RET_OK;
}

ElemType stack_top(STACK * stack)
{
    STACK_CHECK_FAIL(stack);

    if(!stack_is_empty(stack))
    {
        return stack->next->Element;
    }

    return (ElemType)(-1);
}

int stack_make_empty(STACK * stack)
{
    STACK_CHECK_FAIL(stack);

    while(!stack_is_empty(stack))
    {
        stack_pop(stack);
    }    

    return STACK_RET_OK;
}

int stack_traverse(STACK * stack)
{
    STACK_CHECK_FAIL(stack);
    
    printf("\nStack have follow elements : \n");

    while(stack && stack->next)
    {
        printf("element=%d\n", stack->next->Element);
        stack = stack->next;
    }

    return 0;
}

void stack_main_test(void)
{
    //int a=1, b=2, c=3;
    
    STACK * stack = stack_init();

    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);

    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    //stack_pop(stack);
    //stack_pop(stack);
    //stack_push(stack, "1");

    printf("top=%d\n", stack_top(stack));

    stack_traverse(stack);
}

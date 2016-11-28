#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"



bool symbol_is_left(char * str)
{
    if( (*str=='[') || (*str=='(') || (*str=='{') )
        return true;
    else 
        return false;
}

bool symbol_is_right(char * str)
{
    if( (*str==']') || (*str==')') || (*str=='}') )
        return true;
    else 
        return false;
}

bool symbol_is_opposite(char leftStr, char rightStr)
{
    printf("leftStr:%c      rightStr:%c\n", leftStr, rightStr);
    if( ((leftStr=='[')&&(rightStr==']'))  ||
         ((leftStr=='(')&&(rightStr==')'))  ||
         ((leftStr=='{')&&(rightStr=='}'))    )
         return true;
    else
        return false;
}

void stack_balance_symbol_main(void)
{
    char test[] = "{()()}()[]";
    int i = 0;
    
    STACK * stack = stack_init();

    printf("len:%d\n", strlen(test));
    
    for(i=0; i<strlen(test); i++)
    {
        if(symbol_is_left(&test[i]))
        {
            //stack_push(stack, &test[i]);
        }
        else if(symbol_is_right(&test[i]))
        {
            if(true == symbol_is_opposite(stack_top(stack), test[i]))
                stack_pop(stack);
            else
                break;
        }
    }

    if(true == stack_is_empty(stack))
    {
        printf("It's balance symbol\n");
    }
    else
    {
        printf("It's not balance symbol\n");
    }
}

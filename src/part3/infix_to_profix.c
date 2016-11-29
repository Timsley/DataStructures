#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

bool infix_to_profix_is_number(char str)
{
    if(str>='0' && str<='9')
        return true;
    else 
        return false;
}

void infix_to_profix_is_symbol(STACK * inputStack, STACK * outputStack, char str)
{
    char value = 0;
    
    if('(' == str)
    {
        stack_push(inputStack, str);
    }
    else if(')' == str)
    {
        while((true != stack_is_empty(inputStack)) && ('(' != stack_top(inputStack)) )
        {
            value = stack_pop(inputStack);
            printf("%c ", value);
            profix_expression_in(outputStack, &value);
        }
        
        stack_pop(inputStack);       // pop ')'
    }
    else if('+'==str || '-'==str)
    {
        // pop the low or the same priority string in the Stack
        while((true != stack_is_empty(inputStack)) && ('(' != stack_top(inputStack)))                                            
        {
            value = stack_pop(inputStack);
            printf("%c ", value);
            profix_expression_in(outputStack, &value);
        }

        stack_push(inputStack, str);
    }
    else if('*'==str || '/'==str)
    {
        // pop the low or the same priority string in the Stack
        while((true != stack_is_empty(inputStack)) && ('*'==stack_top(inputStack) || '/'==stack_top(inputStack)))       
        {
            value = stack_pop(inputStack);
            printf("%c ", value);
            profix_expression_in(outputStack, &value);
        }
        
        stack_push(inputStack, str);
    }
}

void infix_to_profix_read(STACK * inputStack, STACK * outputStack, char * str)
{
    char *p = str;
    int  value = 0;
    
    while(*p != '\0')
    {
        if(' ' != *p)
        {
            if(true == infix_to_profix_is_number(*p))
            {
                printf("%c ", *p);
                profix_expression_in(outputStack, p);
            }
            else
            {
                infix_to_profix_is_symbol(inputStack, outputStack, *p);
            }
        }
        
        p = p + 1;
    }

    while(true != stack_is_empty(inputStack))
    {
        value = stack_pop(inputStack);
        printf("%c ", value);
        profix_expression_in(outputStack, &value);
    }
}

void infix_to_profix_main_test(void)
{
//    char string[] = "1 + ( 2 - 1 ) * 3";              // profix (1 2 1 - 3 * +), result (4)
//    char string[] = "1 + ( ( 2 + 3 ) * 4 ) - 5";    // profix (1 2 3 + 4 * + 5 -), result (16)
//    char string[] = "5 + ( 2 + 3 ) * 4 / 5";        // profix (5 2 3 + 4 * 5 / -), result (9)
//    char string[] = "4 + 5 + ( 6 * 7 )";                // profix (4 5 + 6 7 * +), result (51)
    char string[] = "6 * ( 5 + ( 2 + 3 ) * 8 + 3 )";        // profix (5 2 3 + 4 * 5 / -), result (9)
    

    
    STACK * inputStack = stack_init();
    STACK * outputStack = stack_init();

    printf("Infix is  : %s\n", string);
    printf("Profix is : ");
    infix_to_profix_read(inputStack, outputStack, string);    
    
    printf("\ncalculate result = %d\n", stack_pop(outputStack));
}

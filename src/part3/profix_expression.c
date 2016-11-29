#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


bool profix_expression_is_operator(char str)
{
    if('+'==str || '-'==str || '*'==str || '/'==str)
        return true;
    else 
        return false;
}

bool profix_expression_is_num(char str)
{
    if(str>='0' && str<='9')
        return true;
    else 
        return false;
}

int profix_expression_calculate(int num1, int num2, char oper)
{
    if('+' == oper)
        return num1 + num2;
    else if('-' == oper)
        return num1 - num2;
    else if('*' == oper)
        return num1 * num2;
    else if('/' == oper)
        return num1 / num2;

    return 0;
}

/* Insert the number into the Stack */
void profix_expression_in(STACK * stack, char * str)
{
    int result=0, num1=0, num2=0;    
    
    if(true == profix_expression_is_num(*str))
    {
        stack_push(stack, atoi(str));
    }
    else if(true == profix_expression_is_operator(*str))
    {
        num2 = stack_pop(stack);
        num1 = stack_pop(stack);
        result = profix_expression_calculate(num1, num2, *str);

        stack_push(stack, result);
    }
}

/* Read the string and insert the number into stack */
void profix_expression_read(STACK * stack, char * str)
{
    char *p = str;
    
    while(*p != '\0')
    {
        if(' ' != *p)
        {
            profix_expression_in(stack, p);
        }
        
        p = p + 1;
    }
    
    printf("calculate result = %d\n", stack_pop(stack));
}

void profix_expression_main_test(void)
{    
    char string[] = "6 5 2 3 + 8 * + 3 + *";        // Infix is 6*(5+(2+3)*8 + 3)
     //char string[] = "6 2 3 + * 2 /";
    
    STACK * stack = stack_init();
    
    printf("Standard is  : %s\n", "6 * ( 5 + ( 2 + 3 ) * 8 + 3 )");
    printf("Profix   is  : %s\n", string);
    
    profix_expression_read(stack, string);
}

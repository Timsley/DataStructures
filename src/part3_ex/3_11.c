#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "single_list.h"


/* find elelment without recursion */
int find_element_without_recursion(LIST *list, ElementType value)
{
    LIST *p = list->next;

    while(p)
    {
        if(p->value == value)
            return 1;
        p = p->next;
    }

    return -1;
}

/* find elelment with recursion */
int find_element_with_recursion(LIST *list, ElementType value)
{    
    if(!list)
        return -1;
        
    if(list->value == value)
        return 1;
    else
        find_element_with_recursion(list->next, value);
}

void ex_3_11(void)
{
    int i;
    
    LIST * list = single_list_create();
    
    for(i=1; i<=10; i++)
        single_list_insert(list, i);
    
    single_list_traverse(list);    

    printf("\n(without recursion) Find %2d in the List, Result : %2d\n", 4, find_element_without_recursion(list, 4));
    printf("(with    recursion) Find %2d in the List, Result : %2d\n\n", 14, find_element_with_recursion(list->next, 14));
}

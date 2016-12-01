#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "single_list.h"

void intersetion(LIST * l1, LIST *l2, LIST *ret)
{
    LIST *p, *q;

    if(l1->next->value < l2->next->value)
    {
        p = l1->next;
        q = l2->next;
    }
    else
    {
        p = l2->next;
        q = l1->next;
    }

    while(p && q)
    {
        //printf("p->value:%d     q->value:%d\n", p->value, q->value);
        if(p->value == q->value)
        {
            single_list_insert(ret, p->value);
            p = p->next;
            q = q->next;
        }
        else if(p->value > q->value)
        {
            q = q->next;
        }
        else if(p->value < q->value)
        {
            p = p->next;
        }
    }
}

void ex_3_4(void)
{
    LIST * l1 = single_list_create();    
    single_list_insert(l1, 1);  
    single_list_insert(l1, 2);  
    single_list_insert(l1, 3);  
    single_list_insert(l1, 4);
    single_list_insert(l1, 5);
    
    LIST * l2 = single_list_create();    
    single_list_insert(l2, 2);  
    single_list_insert(l2, 4);  
    single_list_insert(l2, 6);  
    
    LIST * ret = single_list_create();  
    intersetion(l1, l2, ret);
    
    printf("L1 ");
    single_list_traverse(l1);   
    printf("L2 ");
    single_list_traverse(l2);   
    
    printf("\nAfter Intersetion : ");
    single_list_traverse(ret);   
}

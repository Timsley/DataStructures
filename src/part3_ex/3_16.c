#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "single_list.h"


/* remove the duplicate element in the list, include the duplicate element */
void remove_duplicate_element(LIST *list, ElementType value)
{
    LIST *before, *p;

    before = list;
    p = list->next;
    
    while(p)
    {
        //printf("before:%d,    p:%d,\n", before->value, p->value);
        if(value == p->value)
        {
            while(p->next && (p->value == p->next->value))
                p = p->next;
            before->next = p->next;
        }
        before = p;
        p = p->next;            
    }
}

/* remove the duplicate element in the list, not include the duplicate element */
void remove_duplicate(LIST *list)
{
    LIST *p, *q, *pre;

    if(!list && !list->next && !list->next->next)
        return;    

    p = list->next;

    while(p && p->next)
    {
        //printf("p:%d,    q:%d,\n", p->value, q->value);
        q = p->next;
        pre = p;

        while(q)
        {
            if(p->value == q->value)
            {
                q = q->next;
                pre->next = q;
            }
            else
            {
                pre = pre->next;
                q = q->next;
            }
        }

        p = p->next;
    }
}

void ex_3_16(void)
{
    int i;
    
    LIST * list = single_list_create();
    
    for(i=1; i<=10; i++)
        single_list_insert(list, i);
    for(i=1; i<=10; i++)
        single_list_insert(list, i);

    printf("\nBefore Remove Duplicate : \n");
    single_list_traverse(list);    
    
    remove_duplicate(list);

    printf("\nAfter Remove Duplicate : \n");
    single_list_traverse(list);   
}

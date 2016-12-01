#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "single_list.h"

/* swap the neighbouring two elements in Single Linked List */
void swap_with_next(LIST * list)
{
    Node * h = list;
    Node * p, *q;

    p = h->next;
    q = p->next;

    while(p && q)
    {
        p->next = q->next;
        h->next = q;
        q->next = p;

        if(p->next)
        {
            if(p->next->next)
            {
                q = p->next->next;
                h = p;
                p = p->next;
            }
            else
                break;
        }
        else
            break;
    }
}

void ex_3_3_1(void)
{
    int i;
    
    LIST * list = single_list_create();
    
    for(i=1; i<=10; i++)
        single_list_insert(list, i);

    printf("\nBefore Swap : \n");

    single_list_traverse(list);    

    printf("\nAfter Swap : \n");
    
    swap_with_next(list);    
    single_list_traverse(list);   
}

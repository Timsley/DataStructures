#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "doubly_linked_list.h"


void swap_element(DList * dList)
{
    Node * h = dList;
    Node * p, *q;

    p = h->next;
    q = p->next;

    while(p && q)
    {
        h->next = q;
        q->prev = h;
        p->next = q->next;
        if(q->next)
        {
            q->next->prev = p;
        }
        q->next = p;
        p->prev = q;

        if(p->next)
        {
            if(p->next->next)
            {
                q = p->next->next;
                h = p;
                p = p->next;
                //printf("h:%d, p:%d, q:%d\n",h->value, p->value, q->value);
            }
            else
                break;
        }
        else
            break;
    }
}

void ex_3_3_2(void)
{
    int i=0;
    
    DList * dlist = doubly_linked_list_init();

    for(i=1; i<=10; i++)
        doubly_linked_list_insert(dlist, i);	

    printf("\nBefore Swap : \n");
    doubly_linked_list_traverse_fordward(dlist);
    doubly_linked_list_traverse_backward(dlist);

    swap_element(dlist);
    
    printf("\After Swap : \n");
    doubly_linked_list_traverse_fordward(dlist);
    doubly_linked_list_traverse_backward(dlist);
}

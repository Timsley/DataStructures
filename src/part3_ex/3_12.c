#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "single_list.h"

void reverse_new(LIST *list)
{
    LIST *before, *current, *after;

    before = NULL;
    current = list->next;
    after = current->next;

    while(after)
    {
        current->next = before;
        before = current;
        current = after;
        after = after->next;
    }

    current->next = before;

    list->next = current;
}

void reverse(LIST *list)
{
    LIST *head = list;

    if(!head)
        return;

    if(!head->next)
        return;

    if(!head->next->next)
        return;

    LIST *p, *q;
    p = head->next->next;
    q = p->next;

    head->next->next = NULL;

    while(p)
    {
        p->next = head->next;
        head->next = p;

        p = q;
        if(q)
        {
            q = q->next;
        }
    }

    
}

void ex_3_12(void)
{
    int i;
    
    LIST * list = single_list_create();
    
    for(i=1; i<=10; i++)
        single_list_insert(list, i);

    printf("\nBefore reverse : \n");

    single_list_traverse(list);    

    printf("\nAfter reverse : \n");
    
    reverse_new(list);    
    single_list_traverse(list);   
}

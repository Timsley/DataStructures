#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "single_list.h"

LIST * single_list_create(void)
{
    LIST * list = (LIST *)malloc(sizeof(LIST));
    if(!list)
    {
        printf("malloc list fail\n");
        return NULL;
    }
    
    memset(list, 0, sizeof(LIST));
    list->next = NULL;

    return list;
}

bool single_list_is_empty(LIST * list)
{
    return list->next == NULL;
}

bool single_list_find(LIST * list, ElementType value)
{    
    LIST * pTemp = list->next;

    while(pTemp)
    {
        if(pTemp->value == value)
            return true;
        pTemp = pTemp->next;
    }

    return false;
}

int single_list_insert(LIST * list, ElementType value)
{
     LIST * pTemp = list;
     
     while(pTemp->next  != NULL)
     {
        pTemp = pTemp->next;
     }
     
     LIST * node = (LIST * )malloc(sizeof(Node));
     if(!node)
     {
         printf("single_list_insert_at_tail malloc failed! \n");
         return -1;
     }
     
     node->value = value;
     node->next = NULL;
     
     pTemp->next= node;   
     
    return 0;

}

int single_list_delete(LIST*  list, ElementType *value, int index)
{    
    LIST * pTemp = list;
    LIST * qTemp;
    int i=1;

    while(pTemp->next && i<index)
    {
        pTemp = pTemp->next;
        i++;
    }

    if(pTemp->next == NULL || i>index)
    {
        printf("The index is not exist\n");
        return -1;
    }
    
    qTemp = pTemp->next;
    *value = qTemp->value;
    pTemp->next = qTemp->next;
    
    free(qTemp);
    
    return 0;
}

int single_list_uninit(LIST * list)
{
    LIST * pTemp;

    while(list)
    {        
        pTemp = list->next;
        free(list);
        list = pTemp;
    }

    return 0;
}

void single_list_traverse(LIST * list)
{
    LIST * pTemp = list->next;
    
    printf("List traverse : ");

    while(pTemp != NULL)
    {
        printf("%2d  ", pTemp->value);
        pTemp = pTemp->next;
    }
    printf("\n");
}


void single_list_main_test(void)
{
    int i;
    
    LIST * list = single_list_create();
    
    for(i=1; i<=10; i++)
        single_list_insert(list, i);

    single_list_traverse(list);    
}

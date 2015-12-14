#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "part3_list.h"


LINK_LIST_T link_list_Init(VOID)
{
    LINK_LIST_T pList = (LINK_LIST_T)malloc(sizeof(NODE_T)); 
    if(!pList)
    {
        printf("link_list_Init malloc failed! \n");
        return NULL;
    }
    
    pList->next = NULL;

    return pList;
}

BOOL link_list_is_empty(LINK_LIST_T pList)
{
    return pList->next == NULL;
}


/*
**  How to distinguish the same element
*/
BOOL link_list_is_last(ElementType element, LINK_LIST_T list)
{
    LINK_LIST_T temp;
    temp = list->next;
    
    while(temp && temp->element != element)
        temp = temp->next;

    if(temp == NULL && temp->element == element)
        return TRUE;
    else
        return FALSE;
}

POSITION link_list_find(ElementType element, LINK_LIST_T list)
{
    POSITION temp;
    temp = list->next;
    
    while(temp)
    {
        if(temp->element == element)
            return temp;
        temp = temp->next;
    }

    return NULL;
}


INT32 link_list_insert_at_tail(ElementType element, LINK_LIST_T pList)
{
    LINK_LIST_T pTemp = pList;
    
    while(pTemp->next  != NULL)
    {
       pTemp = pTemp->next;
    }
    
    LINK_LIST_T node = (LINK_LIST_T)malloc(sizeof(NODE_T));
    if(!node)
    {
        printf("link_list_insert_at_tail malloc failed! \n");
        return LISTR_FAIL;
    }
    
    node->element = element;
    node->next = NULL;
    
    pTemp->next= node;   
    
   return LISTR_OK;
}


VOID link_list_traverse(LINK_LIST_T pList)
{
    LINK_LIST_T pTemp = pList->next;

    while(pTemp != NULL)
    {
        printf("node->element : %d\n", pTemp->element);
        pTemp = pTemp->next;
    }
}

VOID link_list_main_test(VOID)
{
    ElementType num1, num2, num3;
    LINK_LIST_T pList = link_list_Init();
    // list = (LINK_LIST_T)malloc(sizeof(NODE_T)); 
    //list->next = NULL;
   // list->element = 99;
    
    num1 = 1, num2=2, num3=3;

    printf("list empty=%d\n", link_list_is_empty(pList));

    link_list_insert_at_tail(num1, pList);
    printf("list empty=%d\n", link_list_is_empty(pList));
    link_list_insert_at_tail(num2, pList);
    //link_list_insert_at_tail(num3, list);
    //link_list_insert_at_tail(&list, 1, num1);
    //link_list_insert_at_tail(&list, 1, num2);
    //link_list_insert_at_tail(&list, 1, num3);


    link_list_traverse(pList);
}




/*
case 1: it is last element
case 2: Cannot find the element in the list
case 3: Can find the element in the list
case 4: Maybe there have same elements
*/
VOID link_list_delete(ElementType element, LINK_LIST_T list)
{
    POSITION pos, temp;
    pos = list->next;

    while(pos)
    {
        if(pos->next->element == element)       // if there have same element, pos->next will point to NULL
        {
            temp = pos->next->next;
            pos->next = NULL;
            free(temp);
            break;
        }
        else
        {
            pos = pos->next;
        }
        #if 0
        if(pos->element == element)
        {
            temp = pos->next;
            pos->next = temp->next;
            free(temp);
        }
        pos = pos->next;
        #endif
    }
    
}

#if 0

void Delete(ElementType X, List L)
{
    Position P, tempCell;
    
    if(IsEmpty(L))
        return;

    P = L->Next;
    
    while(!P)
    {
        if(X == P->Element)
        {
            tempCell = P->Next;
            P->Next = tempCell->Next;
            free(tempCell);
         }
        P = P->Next;
    }
}


Position FindPrevious(ElementType X, List L)
{
    Position P;
    P = L;
    
    while(P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }

    return P;
}

void Insert(ElementType X, List L, Position P)
{

}

List MakeEmpty(List L);
void DeleteList(List L);
Position Header();
Position First(List L);
Position Advance(List L);
ElementType Retrieve(Position P);
#endif


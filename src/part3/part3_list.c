#include <stdio.h>
#include "part3_list.h"


int IsEmpty(List L)
{
    return L->Next == NULL;
}


int IsLast(Position P, List L)
{
    return (P->Next == NULL);        
}

Position Find(ElementType X, List L)
{
    Position P;
    P = L->Next;
    
    while(P != NULL && P->Element != X)
        P = P->Next;

    return P;
}

void Delete(ElementType X, List L)
{
    Position P, tempCell;
    
    if(IsEmpty(L))
        return -1;

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

#if 0
List MakeEmpty(List L);
void DeleteList(List L);
Position Header();
Position First(List L);
Position Advance(List L);
ElementType Retrieve(Position P);
#endif

void part3_list_main_test(void)
{

}

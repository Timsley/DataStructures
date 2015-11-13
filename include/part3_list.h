#ifndef __PART3_LIST_H__
#define __PART3_LIST_H__

typedef int ElementType;
struct node;
typedef struct node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct node
{
    ElementType Element;
    Position Next;
};


List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header();
Position First(List L);
Position Advance(List L);
ElementType Retrieve(Position P);

#endif
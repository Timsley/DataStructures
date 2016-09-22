#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct Node_T
{
    ElemType value;
    struct Node_T * previous;
    struct Node_T * next;
}Node;

typedef struct Node_T CList;



CList * circulayly_linked_list_init(void)
{
    	CList * clist = (CList *)malloc(sizeof(CList));
	if(!clist)
	{
		printf("malloc clist fail!\n");
		return NULL;
	}

	memset(clist, 0, sizeof(CList));
    
	clist->previous = clist;
	clist->next = clist;	

	return clist;
}

/*  insert element at the tail of the list */
void circulayly_linked_list_insert(CList *clist, ElemType value)
{
	if(NULL == clist)
	{
		printf("clist is NULL\n");
		return;
	}
	
	Node * node = (Node *)malloc(sizeof(Node));
	if(!node)
	{
		printf("malloc node fail!\n");
		return;
	}
	memset(node, 0, sizeof(Node));
	node->value = value;

	clist->previous->next = node;
	node->next = clist;

	node->previous = clist->previous;
	clist->previous = node;
}

/* delete element by the index */
void circulayly_linked_list_delete(CList *clist, int index)
{
	int i=1;
	
	if(NULL == clist)
	{
		printf("clist is NULL\n");
		return;
	}

	if(index <= 0)
	{
		printf("delete index is error\n");
		return;
	}
	
	CList *pCList = clist;

	while(i<index && pCList->next!=clist)
	{
		i++;
		pCList = pCList->next;
	}	

	if((i <= index) && (pCList->next == clist))
	{
		printf("delete index:%d, list length:%d\n", index, i-1);
		printf("delete index is bigger than the list length\n");
		return;
	}

	pCList->next->previous = pCList->previous;
	pCList->previous->next = pCList->next;
}

int circulayly_linked_list_find(CList *clist, ElemType value)
{
	CList *plist = clist;
	int index = 1;

	while(plist->next != clist)
	{
		if(plist->value == value)
		{
			printf("Find the element in %d position\n", index);
			return index;
		}
		plist = plist->next;
		index++;
	}
	
	printf("Cannot find the element\n");
	return -1;
}

void circulayly_linked_list_traverse(CList *clist)
{
	CList *plist = clist;

	if(clist->next == clist)
	{
		printf("There is no element in the list\n");
		return;
	}
	
	while(plist->next != clist)
	{
		printf("%d  ", plist->value);
		plist = plist->next;
	}

	printf("\n");
}

void circularly_linked_list_main(void)
{
	CList * head = circulayly_linked_list_init();
	
	circulayly_linked_list_insert(head, 1);
	circulayly_linked_list_insert(head, 2);
	circulayly_linked_list_insert(head, 3);

	circulayly_linked_list_delete(head->next, 1);
	circulayly_linked_list_delete(head->next, 4);

	circulayly_linked_list_find(head->next, 1);

	circulayly_linked_list_traverse(head->next);	
}

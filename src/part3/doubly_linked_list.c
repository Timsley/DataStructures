#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define LIST_MAX_LEN 10

typedef int ElemType;

typedef struct Node_T
{
	ElemType value;
	int length;
	struct Node_T * prev;
	struct Node_T * next;
}Node;

typedef struct Node_T DList;



DList * doubly_linked_list_init(void)
{
	DList * dlist = (DList *)malloc(sizeof(DList));
	if(!dlist)
	{
		printf("malloc dlist fail!\n");
		return NULL;
	}

	memset(dlist, 0, sizeof(DList));
	dlist->length = 0;
	dlist->prev = NULL;
	dlist->next = NULL;	

	return dlist;
}

bool doubly_linked_list_is_empty(DList * dlist)
{	
	return dlist->length == 0;
}

bool double_linked_list_is_full(DList * dlist)
{
	if(dlist->length >= LIST_MAX_LEN)
		return true;
	else 
		return false;
}

/*	insert value at the tail of the list   */
void doubly_linked_list_insert(DList * dlist, ElemType value)
{
	DList * pDList, * insertElem;
	pDList = dlist;

	if(dlist==NULL)
	{
		printf("list is NULL\n");
		return;
	}

	if(true == double_linked_list_is_full(dlist))
	{
		printf("list is full\n");
		return;
	}

	/* Find the tail of the list */
	while(pDList->next)
	{
		pDList = pDList->next;
	}

	insertElem = (DList *)malloc(sizeof(DList));
	if(!insertElem)
	{
		printf("malloc insertElem fail!\n");
		return;
	}
	memset(insertElem, 0, sizeof(DList));
	insertElem->next = NULL;
	insertElem->value = value;

	pDList->next = insertElem;
	insertElem->prev = pDList;

	dlist->length++;
}

/*	delete value by the param index   */
void doubly_linked_list_delete_by_index(DList * dlist, int index)
{
	int count = 0;
	DList * pDList = dlist;
	
	if(dlist==NULL || dlist->next==NULL)
	{
		printf("list is NULL\n");
		return;
	}
	if(index<=0 || index>=LIST_MAX_LEN || index>dlist->length)
	{
		printf("insert index is error\n");
		return;
	}

	while(pDList->next && count<index)
	{
		pDList = pDList->next;
		count ++;
	}

	if(pDList->next == NULL)
	{
		pDList->prev->next = pDList->next;
	}
	else
	{
		pDList->next->prev = pDList->prev;
		pDList->prev->next = pDList->next;
	}
	dlist->length--;
	free(pDList);		/* It need to free the delete element */
}

void doubly_linked_list_traverse_fordward(DList * dlist)
{	
	printf("fordward traverse : ");
	
	while(dlist->next)
	{
		printf("%3d  ", dlist->next->value);	// There have the head fo the Doubly Linked List
		dlist = dlist->next;
	}

	printf("\n");
}

void doubly_linked_list_traverse_backward(DList * dlist)
{
	printf("backward traverse : ");
	
	DList * pDList = dlist;

	/* find the final element */
	while(pDList->next)
		pDList = pDList->next;
	
	while(pDList->prev)
	{
		printf("%3d  ", pDList->value);
		pDList = pDList->prev;
	}

	printf("\n");
}

/* This implement of Doubly Linked List have the head */
void doubly_linked_list_main_test(void)
{
	DList * dlist = doubly_linked_list_init();

	doubly_linked_list_insert(dlist, 1);	
	doubly_linked_list_insert(dlist, 2);	
	doubly_linked_list_insert(dlist, 3);	
	doubly_linked_list_insert(dlist, 4);
	doubly_linked_list_insert(dlist, 5);	
	doubly_linked_list_insert(dlist, 6);	
	doubly_linked_list_insert(dlist, 7);	
	doubly_linked_list_insert(dlist, 8);	
	doubly_linked_list_insert(dlist, 9);	
	doubly_linked_list_insert(dlist, 10);		

//	doubly_linked_list_delete_by_index(dlist, 0);
	doubly_linked_list_delete_by_index(dlist, 5);
	
	doubly_linked_list_traverse_fordward(dlist);
	doubly_linked_list_traverse_backward(dlist);

	printf("DList len is %d\n", dlist->length);
}

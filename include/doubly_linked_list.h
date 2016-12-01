#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__


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



extern DList * doubly_linked_list_init(void);
extern bool doubly_linked_list_is_empty(DList * dlist);
extern bool double_linked_list_is_full(DList * dlist);
/*	insert value at the tail of the list   */
extern void doubly_linked_list_insert(DList * dlist, ElemType value);
/*	delete value by the param index   */
extern void doubly_linked_list_delete_by_index(DList * dlist, int index);
extern void doubly_linked_list_traverse_fordward(DList * dlist);
extern void doubly_linked_list_traverse_backward(DList * dlist);


#endif

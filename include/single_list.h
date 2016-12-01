#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

typedef int ElementType;

typedef struct _LIST_T
{
    ElementType value;
    struct _LIST_T *next;
}LIST;


typedef struct _LIST_T Node;

extern LIST * single_list_create(void);
extern bool single_list_is_empty(LIST * list);
extern bool single_list_find(LIST * list, ElementType value);
extern int single_list_insert(LIST * list, ElementType value);
extern int single_list_delete(LIST * list, ElementType *value, int index);
extern int single_list_uninit(LIST * list);
extern void single_list_traverse(LIST * list);

extern void single_list_main_test(void);

#endif


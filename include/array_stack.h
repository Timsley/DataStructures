#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__


#define ARRAY_STACK_LEN       (10)
#define EMPTY_STACK_INDEX   (-1)

typedef int ElementType;

typedef struct _STACK_T
{
    int stack_size;
    int top_of_stack;
    ElementType * array;
}STACK;

extern void array_stack_main_test(void);

#endif

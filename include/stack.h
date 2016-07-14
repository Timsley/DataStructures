#ifndef __STACK_H__
#define __STACK_H__



#define STACK_RET_OK  (int)1  
#define STACK_RET_NG  (int)(-1)

typedef int ElemType;


#if 0
struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode Stack;

struct Node
{
    ElemType Element;
    PtrToNode * next;
};
#endif

typedef struct STACK_T 
{
    ElemType Element;
    struct STACK_T * next;
}STACK;

typedef struct STACK_T NODE;



#define STACK_CHECK_FAIL(value)        \
            do{                                             \
                if(!value)                                 \
                {                                             \
                    printf("stack is NULLl\n");       \
                    return STACK_RET_NG;        \
                }                                             \
            }while(0)  


extern void stack_main_test(void);


#endif

#ifndef __STACK_H__
#define __STACK_H__



#define STACK_RET_OK  (int)1  
#define STACK_RET_NG  (int)(-1)

typedef int ElemType;
//typedef char ElemType;


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



extern STACK * stack_init(void);
extern bool stack_is_empty(STACK * stack);
extern ElemType stack_pop(STACK * stack);
extern int stack_push(STACK * stack, ElemType ele);
extern ElemType stack_top(STACK * stack);
extern int stack_make_empty(STACK * stack);
extern int stack_traverse(STACK * stack);
extern void stack_main_test(void);


#endif

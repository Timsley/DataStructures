#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__


typedef int ElementType;
typedef int Position;

typedef struct ArrQueue_T
{
    Position front;
    Position rear;
    int size;           // current size of the queue
    ElementType * array;
}ArrQueue;

typedef struct ArrQueue_T Node;


#define ARR_QUEUE_MAX_SIZE 5

extern void array_queue_main_test(void);

#endif


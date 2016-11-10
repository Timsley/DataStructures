#ifndef __queue_H__
#define __queue_H__

typedef int ElementType;

typedef struct QUEUE_T
{
    ElementType value;
    int length;
    struct QUEUE_T *next;
}QUEUE;

typedef struct QUEUE_T Node;



#define QUEUE_MAX_LEN 10

extern void queue_main_test(void);

#endif

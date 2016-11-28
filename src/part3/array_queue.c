#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_queue.h"


ArrQueue * array_queue_create(void)
{
    ArrQueue * queue = (ArrQueue *)malloc(sizeof(ArrQueue));
    if(NULL == queue)
    {
        printf("queue malloc fail\n");
        return NULL;
    }

    queue->array = (ElementType *)malloc(sizeof(ElementType) * ARR_QUEUE_MAX_SIZE);
    if(NULL == queue->array)
    {
        printf("queue->array malloc fail\n");
        return NULL;
    }

    queue->front = 0;
    queue->rear = 0;

    return queue;
}

bool array_queue_is_empty(ArrQueue * queue)
{
    return queue->front == queue->rear;
}

bool array_queue_is_full(ArrQueue * queue)
{
    return queue->front == ((queue->rear + 1)%ARR_QUEUE_MAX_SIZE);
}

/*  Insert element, rear+1 */
int array_queue_in(ArrQueue * queue, ElementType elem)
{
    if(true == array_queue_is_full(queue))
    {
        printf("queue is full, cannot insert\n");
        return -1;
    }   

    queue->array[queue->rear] = elem;
    queue->rear = (queue->rear + 1) % ARR_QUEUE_MAX_SIZE;

    return 0;
}

/*  Delete element, front+1 */
int array_queue_out(ArrQueue * queue)
{
    if(true == array_queue_is_empty(queue))
    {
        printf("queue is empty, cannot delete\n");
        return -1;
    }

    queue->front = (queue->front + 1) % ARR_QUEUE_MAX_SIZE;

    return 0;
}

void array_queue_traverse(ArrQueue * queue)
{
    int i = queue->front;

    while(i != queue->rear)
    {
        printf("value=%d\n", queue->array[i]);
        i = (i+1)%ARR_QUEUE_MAX_SIZE;
    }
}

void array_queue_main_test(void)
{
    ArrQueue * q = array_queue_create();

    array_queue_in(q, 1);
    array_queue_in(q, 2);
    array_queue_in(q, 3);
    array_queue_in(q, 4);
    array_queue_out(q);
    array_queue_out(q);
    array_queue_in(q, 5);
    array_queue_in(q, 6);
    array_queue_in(q, 7);

    array_queue_traverse(q);
}

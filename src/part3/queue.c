#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


QUEUE * queue_create(void)
{
    QUEUE * queue = (QUEUE *)malloc(sizeof(QUEUE));
    if(NULL == queue)
    {
        printf("queue malloc fail\n");
        return NULL;
    }

    memset(queue, 0, sizeof(QUEUE));
    queue->length = 0;
    queue->next = NULL;
    
    return queue;
}

bool queue_is_empty(QUEUE *queue)
{
    return queue->next == NULL;
}

bool queue_is_full(QUEUE *queue)
{
    return queue->length == QUEUE_MAX_LEN;
}

ElementType queue_front(QUEUE *queue)
{
    QUEUE * q = queue;

    if(!q->next)
        return -1;
        
    while(q->next)
        q = q->next;

    return q->value;
}

ElementType queue_back(QUEUE *queue)
{
    return queue->next->value;
}

int queue_in(QUEUE *queue, ElementType elem)
{
#if 0
    if(true == queue_is_full(queue))
    {
        printf("Queue is full\n");
        return -1;
    }
#endif

    Node *node = (Node *)malloc(sizeof(Node));
    if(NULL == node)
    {
        printf("node malloc fail\n");
        return -1;
    }
    memset(node, 0, sizeof(Node));
    
    memcpy(&node->value, &elem, sizeof(ElementType));
    node->next = queue->next;
    
    queue->next = node;
    //queue->length++;

    return 0;
}

void queue_out(QUEUE *queue)
{
    QUEUE *q,*temp;

    q = temp = queue;

    if(!queue || !queue->next)
        return;

    while(q->next)
    {
        temp = q;
        q = q->next;
    }

    temp->next = NULL;
    //queue->length--;
    
    printf("out value=%d\n", q->value);
    free(q);     
}

/* traverse from back to front */
void queue_traverse(QUEUE *queue)
{
    QUEUE * q = queue;
    
    if(!queue || !queue->next)
        return;
    
    while(q->next)
    {
        printf("value=%d\n", q->next->value);
        q = q->next;
    }
}

void queue_main_test(void)
{
    int i;
    QUEUE * q = queue_create();

    for(i=1; i<=10; i++)
        queue_in(q, i);
    
    printf("front:%d\n", queue_front(q));
    printf("back:%d\n", queue_back(q));

    queue_traverse(q);
}

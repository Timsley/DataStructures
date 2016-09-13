#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_LEN 10
#define NUMBER_LEN 3

typedef struct _Node_T
{
    int * number;
    int length;
    int listMaxLen;
}Node;

typedef struct _Node_T * LIST;

LIST radix_sort_init_list(void)
{
    LIST l = (LIST)malloc(sizeof(Node));
    if(NULL == l)
    {
        printf("List malloc fail!\n");
        return NULL;
    }
    memset(l, 0, sizeof(Node));

    l->number = (int *)malloc(LIST_LEN * sizeof(int));
    if(NULL == l->number)
    {
        printf("List->number malloc fail!\n");
        return NULL;
    }
    memset(l->number, 0, LIST_LEN * sizeof(int));

    l->length = 0;
    l->listMaxLen = LIST_LEN;    

    return l;
}

void radix_sort_insert(LIST list, int number)
{
    if(list->length >= LIST_LEN)
    {
        printf("List is Full, cannot insert!\n");
        return;
    }

    list->number[list->length] = number;
    list->length++;
}

void radix_sort_traverse(LIST list)
{
    int i=0;

    for(i=0; i<list->length; i++)
        printf("%3d  ", list->number[i]);

    printf("\n");
}


int radix_sort_get_digit(int number, int index)
{
    switch(index)
    {
        case 1:
            return number%10;
        case 2:
            return (number/10)%10;
        case 3:
            return (number/100)%10;
        case 4:
            return (number/1000)%10;
        case 5:
            return (number/10000)%10;
        default:
            printf("It is bigger than the max number len!\n");
    }

    return 0;
}

void radix_sort_proc(LIST list)
{
    int i, j, k, temp;

    for(k=1; k<=NUMBER_LEN; k++)
    {
        for(i=0; i<list->length; i++)
        {
            for(j=i+1; j<list->length; j++)
            {
                if(radix_sort_get_digit(list->number[i], k) > radix_sort_get_digit(list->number[j], k))
                {
                    temp = list->number[i];
                    list->number[i] = list->number[j];
                    list->number[j] = temp;    
                }
            }
        }
    }
}

void radix_sort_main_test(void)
{
    LIST list;
    
    list = radix_sort_init_list();
    
    radix_sort_insert(list, 64);
    radix_sort_insert(list, 8);
    radix_sort_insert(list, 216);
    radix_sort_insert(list, 512);
    radix_sort_insert(list, 27);
    radix_sort_insert(list, 729);
    radix_sort_insert(list, 0);
    radix_sort_insert(list, 1);
    radix_sort_insert(list, 343);
    radix_sort_insert(list, 125);

    radix_sort_proc(list);
    
    radix_sort_traverse(list);    
}

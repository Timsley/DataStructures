#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _NODE_T
{
    int coefficient;
    int exponent;
    struct _NODE_T *next;
}NODE_T;

typedef struct _NODE_T * Polynomial;

void polynomial_insert(Polynomial poly, int coefficient, int exponent)
{
    Polynomial temp = poly;

    while(temp->next)
    {
        temp = temp->next;
    }
    
    Polynomial polynomial = (Polynomial)malloc(sizeof(NODE_T));
    polynomial->coefficient = coefficient;
    polynomial->exponent = exponent;
    polynomial->next = NULL;

    temp->next = polynomial;
}

void polynomial_traverse(Polynomial poly)
{    
    while(poly)
    {
        printf("coefficient:%2d, exponent:%2d\n", poly->coefficient, poly->exponent);
        poly = poly->next;
    }
}

void polynomial_plus(Polynomial poly1, Polynomial poly2, Polynomial * retPoly)
{
    Polynomial tempA, tempB, retValue, head;
    tempA = poly1->next;
    tempB = poly2->next;
    
    head = (Polynomial)malloc(sizeof(NODE_T));
    memset(head, 0, sizeof(NODE_T));
    
    if(!tempA)
    {
        *retPoly = poly2;
        return;
    }
    
    if(!tempB)
    {
        *retPoly = poly1;
        return;
    }

    *retPoly = head;            // record the head

    while(tempA&&tempB)
    {
        printf("A  :  coefficient:%2d, exponent:%2d\n", tempA->coefficient, tempA->exponent);
        printf("B  :  coefficient:%2d, exponent:%2d\n", tempB->coefficient, tempB->exponent);
        
        retValue = (Polynomial)malloc(sizeof(NODE_T));
        memset(retValue, 0, sizeof(NODE_T));
            
        if(tempA->exponent > tempB->exponent)
        {  
            retValue->coefficient = tempA->coefficient;
            retValue->exponent = tempA->exponent;   
            tempA = tempA->next;       
        }
        else if(tempA->exponent == tempB->exponent)
        {
            retValue->coefficient = tempA->coefficient + tempB->coefficient;
            retValue->exponent = tempA->exponent;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        else
        {
            retValue->coefficient = tempB->coefficient;
            retValue->exponent = tempB->exponent;  
            tempB = tempB->next;         
        }
        printf("Sum : coefficient:%2d, exponent:%2d\n\n", retValue->coefficient, retValue->exponent);
        head->next = retValue;
        head = head->next;
    }

    while(tempA)
    {
        head->next = tempA;
        break;
    }

    while(tempB)
    {
        head->next = tempB;
        break;
    }

    printf("\n\n");
}


void polynomial_main_test(void)
{
#if 0       // case 1 
    Polynomial poly1 = (Polynomial)malloc(sizeof(NODE_T));
    memset(poly1, 0, sizeof(NODE_T));
    polynomial_insert(poly1, 10, 3); 
    polynomial_insert(poly1, 9, 2); 
    polynomial_insert(poly1, 9, 1); 
    
    Polynomial poly2 = (Polynomial)malloc(sizeof(NODE_T));
    memset(poly2, 0, sizeof(NODE_T));
    polynomial_insert(poly2, 4, 4); 
    polynomial_insert(poly2, 5, 3); 
    polynomial_insert(poly2, 6, 1); 
    polynomial_insert(poly2, 9, 0); 
#endif
#if 0       // case 2
    Polynomial poly1 = (Polynomial)malloc(sizeof(NODE_T));
    memset(poly1, 0, sizeof(NODE_T));
    polynomial_insert(poly1, 10, 4); 
    polynomial_insert(poly1, 9, 2); 
    polynomial_insert(poly1, 9, 1); 
    
    Polynomial poly2 = (Polynomial)malloc(sizeof(NODE_T));
    memset(poly2, 0, sizeof(NODE_T));
#endif     
    Polynomial poly1 = (Polynomial)malloc(sizeof(NODE_T));
    memset(poly1, 0, sizeof(NODE_T));
    polynomial_insert(poly1, 10, 4); 
    polynomial_insert(poly1, 9, 2); 
    polynomial_insert(poly1, 9, 1); 
    
    Polynomial poly2 = (Polynomial)malloc(sizeof(NODE_T));
    memset(poly2, 0, sizeof(NODE_T));
    polynomial_insert(poly2, 4, 4); 
    polynomial_insert(poly2, 9, 3); 
    polynomial_insert(poly2, 6, 1); 
    polynomial_insert(poly2, 9, 0); 

    
    Polynomial retValue = (Polynomial)malloc(sizeof(NODE_T));
    memset(retValue, 0, sizeof(NODE_T));

    //polynomial_traverse(poly1->next);
    //polynomial_traverse(poly2->next);
   
    polynomial_plus(poly1, poly2, &retValue);
    polynomial_traverse(retValue->next);
}

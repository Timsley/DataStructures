#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "part3_list.h"


LINK_LIST_T link_list_init(VOID)
{
    LINK_LIST_T pList = (LINK_LIST_T)malloc(sizeof(NODE_T)); 
    if(!pList)
    {
        printf("link_list_init malloc failed! \n");
        return NULL;
    }
    
    pList->next = NULL;

    return pList;
}

BOOL link_list_is_empty(LINK_LIST_T pList)
{    
    LINK_LIST_CHK_FAIL(pList, TRUE);
    
    return pList->next == NULL;
}

BOOL link_list_is_last(ElementType element, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, FALSE);
    
    LINK_LIST_T pTemp = pList;

    while(pTemp->next != NULL)      // fine the last node
        pTemp = pTemp->next;

    if(pTemp->element == element)
        return TRUE;
    else 
        return FALSE;
}

/****************************************************************************
***
*** Check the element in the list or not, if find, return TRUE, if not find, return FALSE
***
****************************************************************************/
BOOL link_list_find_element(ElementType element, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, FALSE);
    
    LINK_LIST_T pTemp = pList->next;

    while(pTemp)
    {
        if(pTemp->element == element)
            return TRUE;
        pTemp = pTemp->next;
    }

    return FALSE;
}

/****************************************************************************
***
*** Check the element in the list or not, if find, return the index, if not find, return 0
***
****************************************************************************/
INT32 link_list_find_element_ret_index(ElementType element, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, LISTR_FAIL);
    
    LINK_LIST_T pTemp = pList->next;
    INT32 index = 0;

    while(pTemp)
    {
        index++;
        if(pTemp->element == element)
            return index;
        pTemp = pTemp->next;
    }

    return 0;
}

/****************************************************************************
***
***  Find the element by the index, if find, it can get the element, if not, return FALSE
***
****************************************************************************/
BOOL link_list_find_by_index(ElementType *element, INT32 index, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, FALSE);
    
    LINK_LIST_T pTemp = pList->next;
    INT32 i = 1;

    while(pTemp && i<index)
    {
        pTemp = pTemp->next;
        i++;
    }

    if(!pTemp || i>index)
    {
        printf("Cannot find the index, invalid args!\n");
        return FALSE;
    }

    *element = pTemp->element;
    
    return TRUE;
}

POSITION link_list_find_previous(ElementType element, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, NULL);
    
    LINK_LIST_T pTemp = pList;
    LINK_LIST_T qTemp =  pTemp;

    while(pTemp && pTemp->element != element)
    {
        qTemp = pTemp;
        pTemp = pTemp->next;
    }

    if(!pTemp)
    {
        printf("Cannot find the element in the list!\n");
        return NULL;
    }
    
    return qTemp;
}

INT32 link_list_insert_at_tail(ElementType element, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, LISTR_FAIL);
    
    LINK_LIST_T pTemp = pList;
    
    while(pTemp->next  != NULL)
    {
       pTemp = pTemp->next;
    }
    
    LINK_LIST_T node = (LINK_LIST_T)malloc(sizeof(NODE_T));
    if(!node)
    {
        printf("link_list_insert_at_tail malloc failed! \n");
        return LISTR_FAIL;
    }
    
    node->element = element;
    node->next = NULL;
    
    pTemp->next= node;   
    
   return LISTR_OK;
}

INT32 link_list_insert_at_head(ElementType element, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, LISTR_FAIL);

    LINK_LIST_T pTemp = pList;
    LINK_LIST_T pNext = pList->next;

    LINK_LIST_T node = (LINK_LIST_T)malloc(sizeof(NODE_T));
    if(!node)
    {
        printf("link_list_insert_at_head malloc failed! \n");
        return LISTR_FAIL;
    }

    node->element = element;
    node->next = pNext;

    pTemp->next= node;   

    return LISTR_OK;
}

INT32 link_list_insert_by_index(ElementType element, INT32 index, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, LISTR_FAIL);
    
    LINK_LIST_T pTemp = pList;
    INT32 i = 1; 
    
    while(pTemp && i<index)
    {
        pTemp = pTemp->next;
        i++;
    }

    if(!pTemp || i>index)
    {
        printf("The index is not exist! \n");
        return LISTR_FAIL;        
    }
    
    LINK_LIST_T node = (LINK_LIST_T)malloc(sizeof(NODE_T));
    if(!node)
    {
        printf("link_list_insert_at_head malloc failed! \n");
        return LISTR_FAIL;
    }
    
    node->element = element;
    node->next = pTemp->next;
    pTemp->next = node;

    return LISTR_OK;
}

INT32 link_list_delete_by_index(ElementType *element, INT32 index, LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, LISTR_FAIL);
    
    LINK_LIST_T pTemp = pList;
    LINK_LIST_T qTemp;
    INT32 i=1;

    while(pTemp->next && i<index)
    {
        pTemp = pTemp->next;
        i++;
    }

    if(pTemp->next == NULL || i>index)
    {
        printf("The index is not exist\n");
        return LISTR_FAIL;
    }
    
    qTemp = pTemp->next;
    *element = qTemp->element;
    pTemp->next = qTemp->next;
    
    free(qTemp);
    
    return LISTR_OK;
}

INT32 link_list_get_list_len(LINK_LIST_T pList)
{    
    LINK_LIST_CHK_FAIL(pList, LISTR_FAIL);
    
    LINK_LIST_T pTemp = pList;
    INT32 len = 0;

    if(!pList)
    {
        printf("The link list is uninit, pls init it\n");
        return LISTR_FAIL;
    }
    
    while(pTemp->next)
    {
        len++;
        pTemp = pTemp->next;
    }

    return len;
}

INT32 link_list_uninit(LINK_LIST_T pList)
{
    LINK_LIST_T pTemp;

    while(pList)
    {        
        pTemp = pList->next;
        free(pList);
        pList = pTemp;
    }

    return LISTR_OK;
}

VOID link_list_traverse(LINK_LIST_T pList)
{
    LINK_LIST_CHK_FAIL(pList, (void)LISTR_FAIL);
    
    LINK_LIST_T pTemp = pList->next;

    while(pTemp != NULL)
    {
        printf("node->element : %d\n", pTemp->element);
        pTemp = pTemp->next;
    }
}


VOID link_list_main_test(VOID)
{
    INT32 i;
    LINK_LIST_T pList = link_list_init();
    
    for(i=1; i<=10; i++)
        link_list_insert_at_tail(i, pList);

    link_list_traverse(pList);    
    
    if(pList)
    {
        link_list_uninit(pList);
    }
}

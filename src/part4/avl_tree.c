#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "avl_tree.h"
#include "tree_visual_create.h"



int avl_tree_max(int h1, int h2)
{
    if(h1 > h2)
        return h1;
    else 
        return h2;
}

int avl_tree_height(AVL_TREE * tree)
{
    if(NULL == tree)
        return -1;
    else 
        return tree->height;
}

Node * avl_tree_find(AVL_TREE * tree, ElementType value)
{
    Node * node = NULL;

    if(tree)
    {
        if(tree->value == value)
            node = tree;
        else if(tree->value > value)
            node = avl_tree_find(tree->lChild, value);
        else if(tree->value < value)
            node = avl_tree_find(tree->rChild, value);
    }

    return node;
}

Node * avl_tree_find_min(AVL_TREE * tree)
{
    AVL_TREE * node = NULL;

    if(tree)
    {
        if(tree->lChild)
            node = avl_tree_find_min(tree->lChild);
        else 
            node = tree;
    }

    return node;
}

Node * avl_tree_find_max(AVL_TREE * tree)
{
    AVL_TREE * node = NULL;

    if(tree)
    {
        if(tree->rChild)
            node = avl_tree_find_max(tree->rChild);
        else 
            node = tree;
    }

    return node;
}

Position * avl_tree_single_rotate_with_left(AVL_TREE * k2)
{
    Position * k1;

    k1 = k2->lChild;
    k2->lChild = k1->rChild;
    k1->rChild = k2;

    k2->height = avl_tree_max(avl_tree_height(k2->lChild), avl_tree_height(k2->rChild)) + 1;
    k1->height = avl_tree_max(avl_tree_height(k1->lChild), avl_tree_height(k1->rChild)) + 1;

    return k1;
}

Position * avl_tree_single_rotate_with_right(AVL_TREE * k1)
{
    Position * k2;

    k2 = k1->rChild;
    k1->rChild = k2->lChild;
    k2->lChild = k1;

    k1->height = avl_tree_max(avl_tree_height(k1->lChild), avl_tree_height(k1->rChild)) + 1;
    k2->height = avl_tree_max(avl_tree_height(k2->lChild), avl_tree_height(k2->rChild)) + 1;

    return k2;
}

Position * avl_tree_double_rotate_with_left(AVL_TREE * k3)
{
    /* Rotate between k1 and k2 */
    k3->lChild = avl_tree_single_rotate_with_right(k3->lChild);

    /* Rotate between k2 and k3 */
    return avl_tree_single_rotate_with_left(k3);
}

Position * avl_tree_double_rotate_with_right(AVL_TREE * k1)
{
    /* Rotate between k2 and k3 */
    k1->rChild = avl_tree_single_rotate_with_left(k1->rChild);
    
    /* Rotate between k1 and k2 */
    return avl_tree_single_rotate_with_right(k1);
}

AVL_TREE * avl_tree_insert(AVL_TREE * tree, ElementType value)
{
    if(NULL == tree)
    {
        tree = (AVL_TREE *)malloc(sizeof(AVL_TREE));
        if(NULL == tree)
            printf("AVL_TREE malloc failed\n");
        else 
        {
            tree->value = value;
            tree->height = 0;
            tree->lChild = tree->rChild = NULL;
        }
    }
    else if(tree->value > value)
    {
        tree->lChild = avl_tree_insert(tree->lChild, value);
        if(avl_tree_height(tree->lChild) - avl_tree_height(tree->rChild) == 2)
        {
            if(value < tree->lChild->value)
                tree = avl_tree_single_rotate_with_left(tree);
            else
                tree = avl_tree_double_rotate_with_left(tree);
        }
    }
    else if(tree->value < value)
    {
        tree->rChild = avl_tree_insert(tree->rChild, value);
        if(avl_tree_height(tree->rChild)- avl_tree_height(tree->lChild) == 2)
        {
            if(value > tree->rChild->value)
                tree = avl_tree_single_rotate_with_right(tree);
            else
                tree = avl_tree_double_rotate_with_right(tree);
        }
    }    

    tree->height = avl_tree_max(avl_tree_height(tree->lChild), avl_tree_height(tree->rChild)) + 1;

    return tree;
}

Node * avl_tree_delete(AVL_TREE * tree, ElementType value)
{
    AVL_TREE * temp = NULL;
        
    if(NULL == tree)
    {
        printf("Not found the element\n");
    }
    else if(value > tree->value)        /* Go Right */
    {
        tree->rChild = avl_tree_delete(tree->rChild, value);
    }
    else if(value < tree->value)       /* Go Left */
    {
        tree->lChild = avl_tree_delete(tree->lChild, value);
    }
    else if(tree->lChild && tree->rChild)       /* Two Children */
    {
        temp = avl_tree_find_min(tree->rChild);

        tree->value = temp->value;
        tree->rChild = avl_tree_delete(tree->rChild, tree->value);
    }
    else                /* one or zero Children */
    {
        temp = tree;
        if(NULL == tree->lChild)
        {
            tree = tree->rChild;
        }
        else if(NULL == tree->rChild)
        {
            tree = tree->lChild;
        }

        free(temp);
    }

    if(tree)        /* Ignore the free node */
    {        
        /* Update the height of tree */
        tree->height = avl_tree_max(avl_tree_height(tree->lChild), avl_tree_height(tree->rChild)) + 1;

        if(avl_tree_height(tree->lChild) - avl_tree_height(tree->rChild) == 2)
        {
            if(tree->lChild->rChild)
                tree = avl_tree_double_rotate_with_left(tree);
            else
                tree = avl_tree_single_rotate_with_left(tree);
        }
        else if(avl_tree_height(tree->rChild)- avl_tree_height(tree->lChild) == 2)
        {
            if(tree->rChild->lChild)
                tree = avl_tree_double_rotate_with_right(tree);
            else
                tree = avl_tree_single_rotate_with_right(tree);
        }
    }
    
    return tree;
}


void avl_tree_destroy(AVL_TREE * tree)
{
    if(tree)
    {
        if(tree->lChild)
            avl_tree_destroy(tree->lChild);
        if(tree->rChild)
            avl_tree_destroy(tree->rChild);

        free(tree);
    }
}

void avl_tree_main(void)
{
    AVL_TREE * tree = NULL;
    //int i=0;

    //for(i=1; i<=127; i++)
    //    tree = avl_tree_insert(tree, i);
#if 0
    tree = avl_tree_insert(tree, 7);
    tree = avl_tree_insert(tree, 6);
    tree = avl_tree_insert(tree, 10);
    tree = avl_tree_insert(tree, 5);
    tree = avl_tree_insert(tree, 13);
    tree = avl_tree_insert(tree, 8);
    tree = avl_tree_insert(tree, 11);
#endif
#if 0
    tree = avl_tree_insert(tree, 5);
    tree = avl_tree_insert(tree, 3);
    tree = avl_tree_insert(tree, 6);
    tree = avl_tree_insert(tree, 4);
#endif	
#if 0
    tree = avl_tree_insert(tree, 5);
    tree = avl_tree_insert(tree, 2);
    tree = avl_tree_insert(tree, 8);
    tree = avl_tree_insert(tree, 1);
    tree = avl_tree_insert(tree, 4);
    tree = avl_tree_insert(tree, 7);
    tree = avl_tree_insert(tree, 3);
#endif    
#if 0
    tree = avl_tree_insert(tree, 7);
    tree = avl_tree_insert(tree, 6);
    tree = avl_tree_insert(tree, 8);
    tree = avl_tree_insert(tree, 5);
    tree = avl_tree_insert(tree, 9);
    tree = avl_tree_insert(tree, 10);
#endif    
#if 0
    tree = avl_tree_insert(tree, 8);
    tree = avl_tree_insert(tree, 3);
    tree = avl_tree_insert(tree, 10);
    tree = avl_tree_insert(tree, 2);
    tree = avl_tree_insert(tree, 5);
    tree = avl_tree_insert(tree, 9);
    tree = avl_tree_insert(tree, 11);
    tree = avl_tree_insert(tree, 1);
    tree = avl_tree_insert(tree, 4);
    tree = avl_tree_insert(tree, 6);
    tree = avl_tree_insert(tree, 12);
    tree = avl_tree_insert(tree, 7);
#endif
#if 1
    tree = avl_tree_insert(tree, 3);
    tree = avl_tree_insert(tree, 2);
    tree = avl_tree_insert(tree, 4);
    tree = avl_tree_insert(tree, 1);
#endif
    tree_visual_create(tree, "tree_insert.dot");

    Node * min = avl_tree_find_min(tree);
    printf("min value : %d\n", min->value);

    Node * max = avl_tree_find_max(tree);
    printf("max value : %d\n", max->value);

    Node * find = avl_tree_find(tree, 2);
    if(find)
        printf("find value : %d\n", find->value);
    else 
        printf("Cannot find the value\n");

    tree = avl_tree_delete(tree, 4);
    tree_visual_create(tree, "tree_delete.dot");

    avl_tree_destroy(tree);
}

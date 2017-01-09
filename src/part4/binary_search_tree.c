#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search_tree.h"
#include "tree_visual_create.h"


BS_TREE * binary_search_tree_create(void)
{
    char ch;
    BS_TREE *tree;
    
    scanf("%c",&ch);    

    if('#' == ch)
    {
        tree = NULL;
    }
    else
    {
        tree = (BS_TREE *)malloc(sizeof(BS_TREE));
        memset(tree, 0, sizeof(BS_TREE));
        tree->value = ch - '0';

        tree->lChild = binary_search_tree_create();
        tree->rChild = binary_search_tree_create();
    }

    return tree;
}

TNode * binary_search_tree_find(BS_TREE * tree, ElementType value)
{
    TNode * node = NULL;
    
    if(tree)   
    {
        //printf("Now the node value is %d\n", tree->value);
        if(tree->value == value)
            return tree;
        else if(tree->value > value)
            node = binary_search_tree_find(tree->lChild, value);
        else if(tree->value < value)
            node = binary_search_tree_find(tree->rChild, value);            
    }

    return node;
}

TNode * binary_search_tree_find_min(BS_TREE * tree)
{
    TNode * node = NULL;

    if(tree)
    {
        if(tree->lChild)
        {
            node = binary_search_tree_find_min(tree->lChild);
        }
        else
            node = tree;
    }

    return node;
}

TNode * binary_search_tree_find_max(BS_TREE * tree)
{
    TNode * node = NULL;
    
    if(tree)
    {
        if(tree->rChild)
        {
            node = binary_search_tree_find_max(tree->rChild);
        }
        else
            node = tree;
    }

    return node;
}

void binary_search_tree_insert(BS_TREE * tree, ElementType value)
{
    if(tree)
    {
        if(tree->value == value)
        {
            printf("Ingore it, It's the same vlaue.\n");
        }
        else if(tree->value > value)
        {
            if(NULL == tree->lChild)
            {
                TNode * node = (TNode *)malloc(sizeof(TNode));
                memset(node, 0, sizeof(TNode));
                node->value = value;

                tree->lChild = node;
            }
            else
                binary_search_tree_insert(tree->lChild, value);
        }
        else if(tree->value < value)
        {
            if(NULL == tree->rChild)
            {
                TNode * node = (TNode *)malloc(sizeof(TNode));
                memset(node, 0, sizeof(TNode));
                node->value = value;

                tree->rChild = node;
            }
            else
                binary_search_tree_insert(tree->rChild, value);
        }
    }
}

BS_TREE * binary_search_tree_delete(BS_TREE * tree, ElementType value)
{
    BS_TREE * temp = NULL;
        
    if(NULL == tree)
    {
        printf("Not found the element\n");
    }
    else if(value > tree->value)        /* Go Right */
    {
        tree->rChild = binary_search_tree_delete(tree->rChild, value);
    }
    else if(value < tree->value)	   /* Go Left */
    {
        tree->lChild = binary_search_tree_delete(tree->lChild, value);
    }
    else if(tree->lChild && tree->rChild)       /* Two Children */
    {
        temp = binary_search_tree_find_min(tree->rChild);

        tree->value = temp->value;
        tree->rChild = binary_search_tree_delete(tree->rChild, tree->value);
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

    return tree;
}

void binary_search_tree_preorder_traverse(BS_TREE * tree)
{
    if(tree)
    {
        printf("%d  ", tree->value);
        binary_search_tree_preorder_traverse(tree->lChild);
        binary_search_tree_preorder_traverse(tree->rChild);
    }
}

void binary_search_tree_inorder_traverse(BS_TREE * tree)
{
    if(tree)
    {
        binary_search_tree_inorder_traverse(tree->lChild);
        printf("%d  ", tree->value);
        binary_search_tree_inorder_traverse(tree->rChild);
    }
}

void binary_search_tree_postorder_traverse(BS_TREE * tree)
{
    if(tree)
    {
        binary_search_tree_postorder_traverse(tree->lChild);
        binary_search_tree_postorder_traverse(tree->rChild);
        printf("%d  ", tree->value);
    }
}

void binary_search_tree_destroy(BS_TREE * tree)
{
    if(tree)
    {
        binary_search_tree_destroy(tree->lChild);
        binary_search_tree_destroy(tree->rChild);
        
        free(tree);
        tree = NULL;
    }
}

void binary_search_tree_main(void)
{
    BS_TREE * tree = binary_search_tree_create();

    tree_visual_create(tree, "tree.dot");

    TNode * node;
    node = binary_search_tree_find(tree, 7);
    if(node != NULL)
    {
        printf("Find the node value : %d\n", node->value);
    }

    node = binary_search_tree_find_min(tree);
    if(node != NULL)
    {
        printf("Find the Min node value : %d\n", node->value);
    }
    
    node = binary_search_tree_find_max(tree);
    if(node != NULL)
    {
        printf("Find the Max node value : %d\n", node->value);
    }
    
    binary_search_tree_insert(tree, 3);    
    tree_visual_create(tree, "tree2.dot");

    printf("\nPreorder traverse : ");
    binary_search_tree_preorder_traverse(tree);
    
    printf("\nInorder traverse : ");
    binary_search_tree_inorder_traverse(tree);
    
    printf("\nPostorder traverse : ");
    binary_search_tree_postorder_traverse(tree);
    printf("\n");

    tree = binary_search_tree_delete(tree, 4);
    tree_visual_create(tree, "tree3.dot");
    
    binary_search_tree_destroy(tree);   
}

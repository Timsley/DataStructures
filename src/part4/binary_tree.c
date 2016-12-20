#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "tree_visual_create.h"


BI_TREE * binary_tree_create(void)
{
    char ch;
    scanf("%c",&ch);
    BI_TREE *tree;
    
    //printf("input %c      \n", ch);

    if('#' == ch)
    {
        tree = NULL;
    }
    else
    {
        tree = (BI_TREE *)malloc(sizeof(BI_TREE));
        tree->value = ch;

        tree->lChild = binary_tree_create();
        tree->rChild = binary_tree_create();
    }

    return tree;
}

void binary_tree_preorder_traverse(BI_TREE * tree)
{
    if(tree)
    {
        printf("%c  ", tree->value);
        binary_tree_preorder_traverse(tree->lChild);
        binary_tree_preorder_traverse(tree->rChild);
    }
}

void binary_tree_inorder_traverse(BI_TREE * tree)
{
    if(tree)
    {
        binary_tree_inorder_traverse(tree->lChild);
        printf("%c  ", tree->value);
        binary_tree_inorder_traverse(tree->rChild);
    }
}

void binary_tree_postorder_traverse(BI_TREE * tree)
{
    if(tree)
    {
        binary_tree_postorder_traverse(tree->lChild);
        binary_tree_postorder_traverse(tree->rChild);
        printf("%c  ", tree->value);
    }
}

void binary_tree_main_test(void)
{
    BI_TREE  *tree = binary_tree_create();

    printf("value : %c\n", tree->value);

    printf("\nPreorder traverse : ");
    binary_tree_preorder_traverse(tree);
    
    printf("\nInorder traverse : ");
    binary_tree_inorder_traverse(tree);
    
    printf("\nPostorder traverse : ");
    binary_tree_postorder_traverse(tree);
    printf("\n");

    tree_visual_create(tree, "tree.dot");
}

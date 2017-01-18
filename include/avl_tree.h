#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__


typedef int ElementType;

typedef struct AVL_TREE_T
{
    ElementType value;
    struct AVL_TREE_T * lChild;
    struct AVL_TREE_T * rChild;
    int height;
}AVL_TREE;

typedef AVL_TREE Node;
typedef AVL_TREE Position;


extern void avl_tree_main(void);

#endif

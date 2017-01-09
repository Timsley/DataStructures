#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__


typedef int ElementType;

typedef struct BS_TREE_T
{
    ElementType value;
    struct BS_TREE_T * lChild;
    struct BS_TREE_T * rChild;
}BS_TREE;

typedef struct BS_TREE_T TNode;

extern void binary_search_tree_main(void);

#endif

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__


typedef int ElementType ;

typedef struct BI_TREE_T
{
    ElementType value;
    struct BI_TREE_T *lChild;
    struct BI_TREE_T *rChild;
}BI_TREE;


extern void binary_tree_main_test(void);

#endif

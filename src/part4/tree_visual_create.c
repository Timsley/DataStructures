#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "tree_visual_create.h"


void tree_create_dot(BI_TREE * node, FILE* stream)
{
    if(node->lChild)
    {        
        fprintf(stream," %c -> %c;\n", (node->value), (node->lChild->value));
        if(NULL == node->rChild)
        {
            fprintf(stream," %c -> null%c[weight=100, style=invis]; null%c[style=invis];\n", (node->value), (node->value), (node->value));
        }
        tree_create_dot(node->lChild, stream);
    }

    if(node->rChild)
    {
        if(NULL == node->lChild)
        {
            fprintf(stream," %c -> null%c[weight=100, style=invis]; null%c[style=invis];\n", (node->value), (node->value), (node->value));
        }
        fprintf(stream," %c -> %c;\n", (node->value), (node->rChild->value));
        tree_create_dot(node->rChild, stream);
    }
}

void tree_visual_create(BI_TREE * tree, char * fileName)
{
    FILE * stream = fopen(fileName,"w+");
    if(stream == NULL)
    {
        fprintf(stderr, "open failed n");
        return;
    }

    fprintf(stream,"digraph {\n");    
    fprintf(stream,"node[width=0.5,height=0.5];\n");
    fprintf(stream,"edge[color=blue, arrowhead=normal];\n");
    fprintf(stream,"nodesep=0.5;\n");
    
    tree_create_dot(tree, stream);

    fprintf(stream,"}\n");
    fclose(stream);

    return;    
}

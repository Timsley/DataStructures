#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"
#include "tree_visual_create.h"


void tree_create_dot(BS_TREE * node, FILE* stream)
{
    if(node->lChild)
    {        
        fprintf(stream,"  %d -> %d;\n", (node->value), (node->lChild->value));
        if(NULL == node->rChild)
        {
            fprintf(stream,"  %d -> null%d[weight=100, style=invis]; null%d[style=invis];\n", (node->value), (node->value), (node->value));
        }
        tree_create_dot(node->lChild, stream);
    }

    if(node->rChild)
    {
        if(NULL == node->lChild)
        {
            fprintf(stream,"  %d -> null%d[weight=100, style=invis]; null%d[style=invis];\n", (node->value), (node->value), (node->value));
        }
        fprintf(stream,"  %d -> %d;\n", (node->value), (node->rChild->value));
        tree_create_dot(node->rChild, stream);
    }
#if 0
    if( (node->lChild==NULL) && (node->rChild==NULL) && (node != NULL))
    {
        fprintf(stream,"  %d ;\n", (node->value));
    }
    #endif
}

void tree_visual_create(BS_TREE * tree, char * fileName)
{
    FILE * stream = fopen(fileName,"w+");
    if(stream == NULL)
    {
        fprintf(stderr, "open failed n");
        return;
    }

    fprintf(stream,"digraph {\n");    
    fprintf(stream,"  node[width=0.5,height=0.5];\n");
    fprintf(stream,"  edge[color=blue, arrowhead=normal];\n");
    fprintf(stream,"  nodesep=0.5;\n\n");
    
    tree_create_dot(tree, stream);

    fprintf(stream,"}\n");
    fclose(stream);

    return;    
}

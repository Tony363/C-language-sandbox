#ifndef _graph_h
#define _graph_h

#include <stdio.h>

typedef struct _ChildNode
{
    int child_idx;
    double cost;
    struct _ChildNode *next;
} ChildNode;

typedef struct _ParentNode
{
    char *name;
    ChildNode *children;
} ParentNode;

typedef struct _Graph
{
    int num_vertices;
    ParentNode *vertices;
} Graph;

ChildNode *createChildNode(int idx, double cost);
ParentNode *createParentNode(const char *name);
void initParentNode(ParentNode *n, const char *name);
void freeChildNode(ChildNode *n);
void freeParentNode(ParentNode *n);

Graph *buildGraph(FILE *input);
void printGraph(Graph *g);
void freeGraph(Graph *g);

#endif

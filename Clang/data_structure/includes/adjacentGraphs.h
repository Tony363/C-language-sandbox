#ifndef ADJACENTGRAPHS_H
#define ADJACENTGRAPHS_H
#include <stdio.h>
typedef struct ajNode
{
    char vertex;
    int edge;
    struct ajNode *next;
} ajNode;

typedef struct adjList
{
    char vertex;
    ajNode *head;
} adjList;

typedef struct Graph
{
    char *direction;
    int V;
    int *flag;
    adjList *array;
} Graph;

ajNode *newAGraphNode(char vertex, int edge);
Graph *newGraph(int V, char *d);
void addGraphNode(Graph *graph, char vSrc, char vDst, int edge);
void printAdjList(Graph *graph);
void freeGraph(Graph *graph);

/**************************************************************************/

typedef struct _childNode
{
    int child_idx;
    double cost;
    struct _childNode *next;
} ChildNode;

typedef struct _ParentNode
{
    char *name;
    ChildNode *children;
} ParentNode;

typedef struct _Graph
{
    ParentNode *vertices;
    int num_vertices;
} GraphFCC;

ChildNode *createChildNode(int idx, double cost);
ParentNode *createParentNode(const char *name);
void initParentNode(ParentNode *n, const char *name);
void freeChildNode(ChildNode *n);
void freeParentNode(ParentNode *n);

GraphFCC *buildGraph(FILE *input);
void freeGFCC(GraphFCC *g);
#endif
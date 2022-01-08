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
#endif
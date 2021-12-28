#ifndef ADJACENTGRAPHS_H
#define ADJACENTGRAPHS_H
typedef struct ajNode
{
    char vertex;
    int edge;
    struct ajNode *next;
} ajNode;

typedef struct adjList
{
    ajNode *head;
} adjList;

typedef struct Graph
{
    char *direction;
    int V;
    adjList *array;
} Graph;

ajNode *newAGraphNode(char vertex, int edge);
Graph *newGraph(int V, char *d);
void addGraphNode(Graph *graph, char vSrc, char vDst, int edge);
void printAdjList(Graph *graph);
#endif
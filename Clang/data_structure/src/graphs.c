#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/adjacentGraphs.h"

ajNode *newAGraphNode(char vertex, int edge)
{
    ajNode *newNode = (ajNode *)malloc(sizeof(ajNode));
    newNode->vertex = vertex;
    newNode->edge = edge;
    newNode->next = NULL;
    return newNode;
}

Graph *newGraph(int V, char *d)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->direction = (char *)malloc(sizeof(char) * strlen(d));
    strcpy(newGraph->direction, d);
    newGraph->V = V;
    newGraph->array = (adjList *)malloc(V * sizeof(adjList));
    for (int i = 0; i < V; i++)
        newGraph->array[i].head = NULL;
    return newGraph;
}

void addGraphNode(Graph *graph, char vSrc, char vDst, int edge)
{
    int srcIdx = vSrc - 'A', dstIdx = vDst - 'A';

    ajNode *srcNewNode = newAGraphNode(vSrc, edge);

    if (!graph->array[srcIdx].head)
    {
        srcNewNode->next = graph->array[srcIdx].head;
        graph->array[srcIdx].head = srcNewNode;
    }
    else
    {
        ajNode *temp = graph->array[srcIdx].head;
        while (temp->next)
            temp = temp->next;
        temp->next = srcNewNode;
    }
    if (strcmp(graph->direction, "--") == 0)
    {
        ajNode *dstNewNode = newAGraphNode(vDst, edge);
        if (!graph->array[dstIdx].head)
        {
            dstNewNode->next = graph->array[dstIdx].head;
            graph->array[dstIdx].head = dstNewNode;
        }
        else
        {
            ajNode *temp = graph->array[dstIdx].head;
            while (temp->next)
                temp = temp->next;
            temp->next = dstNewNode;
        }
    }

    // TODO
    // search by edge value that connects 2 vertexes
    // make them undirected
}

void printAdjList(Graph *graph)
{
    for (int i = 0; i < graph->V; i++)
    {

        ajNode *temp = graph->array[i].head;
        printf("%c ", (temp) ? temp->vertex : ' ');
        while (temp != NULL)
        {
            printf("%s %d ", graph->direction, temp->edge);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    Graph *graph = newGraph(7, "--");
    addGraphNode(graph, 'A', 'B', 25);
    addGraphNode(graph, 'A', 'C', 45);
    addGraphNode(graph, 'B', 'D', 50);
    addGraphNode(graph, 'B', 'F', 55);
    addGraphNode(graph, 'B', 'E', 60);
    addGraphNode(graph, 'B', 'C', 10);
    addGraphNode(graph, 'C', 'G', 70);
    addGraphNode(graph, 'C', 'E', 65);
    addGraphNode(graph, 'D', 'E', 20);
    addGraphNode(graph, 'E', 'F', 30);
    addGraphNode(graph, 'E', 'G', 40);
    addGraphNode(graph, 'F', 'D', 15);
    addGraphNode(graph, 'F', 'G', 35);

    printAdjList(graph);
    return 0;
}
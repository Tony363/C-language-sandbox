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
    newGraph->direction = (char *)malloc(sizeof(char) * strlen(d) + 1);
    strcpy(newGraph->direction, d);
    newGraph->V = V;
    newGraph->array = (adjList *)malloc(V * sizeof(adjList));
    newGraph->flag = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
    {
        newGraph->array[i].head = NULL;
        newGraph->flag[i] = 0;
    }
    return newGraph;
}

void addGraphNode(Graph *graph, char vSrc, char vDst, int edge)
{
    int srcIdx = vSrc - 'A', dstIdx = vDst - 'A';
    // printf("%c %c\n", vSrc, vDst);
    ajNode *srcNewNode = newAGraphNode(vDst, edge);

    if (!graph->array[srcIdx].head)
    {
        srcNewNode->next = graph->array[srcIdx].head;
        graph->array[srcIdx].head = srcNewNode;
        graph->array[srcIdx].vertex = vSrc;
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
        ajNode *dstNewNode = newAGraphNode(vSrc, edge);
        if (!graph->array[dstIdx].head)
        {
            dstNewNode->next = graph->array[dstIdx].head;
            graph->array[dstIdx].head = dstNewNode;
            graph->array[dstIdx].vertex = vDst;
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

// DFS algo
int DFS(Graph *graph, char initV, char searchV)
{
    if (initV == searchV)
        return 1;
    ajNode *temp = graph->array[initV - 'A'].head;

    graph->flag[initV - 'A'] = 1;
    printf("Visited %c \n", initV);

    while (temp)
    {
        char connectedVertex = temp->vertex;
        if (graph->flag[connectedVertex - 'A'] == 0)
            return DFS(graph, connectedVertex, searchV);

        temp = temp->next;
    }
    return 0;
}

void printAdjList(Graph *graph)
{
    for (int i = 0; i < graph->V; i++)
    {

        ajNode *temp = graph->array[i].head;
        printf("%c ", (temp) ? graph->array[i].vertex : ' ');
        while (temp != NULL)
        {
            printf("%c %s %d ", temp->vertex, graph->direction, temp->edge);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        ajNode *temp = graph->array[i].head;
        while (temp != NULL)
        {
            ajNode *temp2 = temp;
            temp = temp->next;
            free(temp2);
        }
    }
    free(graph->direction);
    free(graph->array);
    free(graph);
}

// TODO implement release graph;
// initialize array only in function of DFS
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
    printf(DFS(graph, 'A', 'G') ? "Found\n" : "Not Found\n");
    return 0;
}
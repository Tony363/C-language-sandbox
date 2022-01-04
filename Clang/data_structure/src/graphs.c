#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/adjacentGraphs.h"
#include "../includes/intQueue.h"

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
        newGraph->array[i].head = NULL;

    memset(newGraph->flag, 0, V * sizeof(int));
    return newGraph;
}

void addGraphNode(Graph *graph, char vSrc, char vDst, int edge)
{
    int srcIdx = vSrc - 'A', dstIdx = vDst - 'A';
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
}

void printArr(Graph *graph)
{
    for (int i = 0; i < graph->V; i++)
    {
        printf("%d ", graph->flag[i]);
    }
    printf("\n");
}
// DFS algo
// bugged, infinite recursive loop?
int DFS(Graph *graph, char initV, char searchV)
{
    if (initV == searchV)
    {
        printf("Found %c\n", searchV);
        memset(graph->flag, 0, graph->V * sizeof(int));
        return 1;
    }
    ajNode *temp = graph->array[initV - 'A'].head;

    graph->flag[initV - 'A'] = 1;
    // printArr(graph);
    while (temp)
    {
        char connectedVertex = temp->vertex;
        if (graph->flag[connectedVertex - 'A'] == 0)
            return DFS(graph, connectedVertex, searchV);
        temp = temp->next;
    }
    memset(graph->flag, 0, graph->V * sizeof(int)); // too many traversals because recursive
    return 0;
}

ajNode *next(Graph *graph, ajNode *node)
{
    if (!node)
        return NULL;
    int adjVertex = node->vertex - 'A';
    if (graph->flag[adjVertex] == 1)
        return next(graph, node->next);
    return node;
}

// BFS algorithm
int BFS(Graph *graph, char startVertex, char searchV)
{
    QueueList *q = createQueueIq();

    graph->flag[startVertex - 'A'] = 1;
    enqueue(q, startVertex - 'A');

    while (!QisEmpty(q))
    {
        int currentVertex = dequeue(q);
        ajNode *temp = graph->array[currentVertex].head;
        // printf("Visiting %d children\n", currentVertex);
        while (temp)
        {
            int adjVertex = temp->vertex - 'A';
            // printf("Traversing %d child\n", adjVertex);

            if (temp->vertex == searchV)
            {
                printf("Found %c \n", searchV);
                return 1;
            }
            if (graph->flag[adjVertex] == 0)
            {
                graph->flag[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = next(graph, temp->next);
            // temp = temp->next;
        }
    }
    free(q);
    memset(graph->flag, 0, graph->V * sizeof(int));
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
    free(graph->flag);
    free(graph->direction);
    free(graph->array);
    free(graph);
}

int main(int argc, char **argv)
{
    Graph *graph = newGraph(7, "->");
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
    printf(BFS(graph, 'A', 'G') ? "Found\n" : "Not Found\n");
    freeGraph(graph);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "../includes/intlist.h"
#include "../includes/AdtIntList.h"

typedef struct _QueueList
{
    IntNode *front;
    IntNode *rear;
} QueueList;

int QisEmpty(QueueList *queue)
{
    return queue->front == NULL;
}

QueueList *createQueueIq()
{
    QueueList *queue = (QueueList *)malloc(sizeof(QueueList));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(QueueList *queue, int value)
{
    IntNode *node = (IntNode *)malloc(sizeof(IntNode));
    node = createNodeIL(value);
    if (QisEmpty(queue))
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = queue->rear->next;
    }
}

int dequeue(QueueList *queue)
{
    if (QisEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    IntNode *node = queue->front;
    int value = node->value;
    queue->front = queue->front->next;
    free(node);
    return value;
}

void printQueue(QueueList *queue)
{
    IntNode *node = queue->front;
    while (node)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

void freeQueue(QueueList *queue)
{
    while (!QisEmpty(queue))
    {
        printf("%d ", dequeue(queue));
    }
    free(queue);
    printf("\n%p\n", queue);
}

int peekQ(QueueList *queue)
{
    if (QisEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->value;
}

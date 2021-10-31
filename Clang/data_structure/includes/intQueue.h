#ifndef QUEUELIST_H
#define QUEUELIST_H
#include <stdio.h>
#include <stdlib.h>
#include "../includes/intlist.h"
#include "../includes/AdtIntList.h"

typedef struct _QueueList
{
    IntNode *front;
    IntNode *rear;
} QueueList;

QueueList *createQueueIq();
void enqueue(QueueList *queue, int value);
int dequeue(QueueList *queue);
int QisEmpty(QueueList *queue);
int peekQ(QueueList *queue);
void printQueue(QueueList *queue);
void freeQueue(QueueList *queue);
#endif
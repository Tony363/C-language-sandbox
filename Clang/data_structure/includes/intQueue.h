#ifndef QUEUELIST_H
#define QUEUELIST_H
#include <stdio.h>
#include <stdlib.h>
#include "AdtIntList.h"

QueueList *createQueueIq();
void enqueue(QueueList *queue, int value);
int dequeue(QueueList *queue, int *status);
int QisEmpty(QueueList *queue);
int peekQ();
void printQueue(QueueList *queue);
void freeQueue(QueueList *queue);
#endif
#include "../includes/intqueuea.h"
#include <stdlib.h>

// ring buffer modulo approach
IntQueueA *createIntQueueA(int size)
{
    IntQueueA *q = (IntQueueA *)malloc(sizeof(IntQueueA));
    q->head = -1;
    q->tail = -1;
    q->queueSize = size;
    q->queueAry = (int *)malloc(sizeof(int) * size);
    return q;
}

void freeIntQueueA(IntQueueA *queue)
{
    free(queue->queueAry);
    free(queue);
}

void enqueueIQA(IntQueueA *queue, int value, int *status)
{
    if (isFullIQA(queue))
    {
        if (status)
        {
            *status = -1;
        }
        return;
    }

    if (isEmptyIQA(queue))
    {
        queue->head = queue->tail = 0;
    }
    else
    {
        queue->tail = (queue->tail + 1) % queue->queueSize;
    }
    queue->queueAry[queue->tail] = value;
    if (status)
    {
        *status = 0;
    }
}

// or have ring buffer to waste 1 space to counter for head and tail indexes
int dequeueIQA(IntQueueA *queue, int *status)
{
    int value;

    if (isEmptyIQA(queue))
    {
        if (status)
        {
            *status = -2;
        }
        return 0;
    }

    value = queue->queueAry[queue->head];
    if (queue->head == queue->tail) // case where there is only 1 element in array based queue
    {
        queue->head = queue->tail = -1;
    }
    else
    {
        queue->head = (queue->head + 1) % queue->queueSize;
    }

    if (status)
    {
        *status = 0;
    }
    return value;
}

int peekIQA(IntQueueA *queue, int *status)
{
    int value;

    if (isEmptyIQA(queue))
    {
        if (status)
        {
            *status = -2;
        }
        return 0;
    }

    value = queue->queueAry[queue->head];

    if (status)
    {
        *status = 0;
    }
    return value;
}

int isEmptyIQA(IntQueueA *queue)
{
    return queue->head == -1;
}

int isFullIQA(IntQueueA *queue)
{
    return (queue->tail + 1) % queue->queueSize == queue->head;
}

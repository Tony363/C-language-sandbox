#include <stdio.h>
#include "includes/intqueuea.h"

void printQueue(IntQueueA *q)
{
    int i;
    for (i = 0; i < q->queueSize; i++)
    {
        printf("%d ", q->queueAry[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int status = 0;
    IntQueueA *queue = createIntQueueA(5);
    enqueueIQA(queue, 1, &status);
    enqueueIQA(queue, 2, &status);
    enqueueIQA(queue, 3, &status);
    enqueueIQA(queue, 4, &status);
    enqueueIQA(queue, 5, &status);
    printQueue(queue);
    while (!isEmptyIQA(queue))
    {
        printf("peek: %d\n", peekIQA(queue, &status));
        printf("dequeue: %d\n", dequeueIQA(queue, &status));
    }
    freeIntQueueA(queue);
    return 0;
}
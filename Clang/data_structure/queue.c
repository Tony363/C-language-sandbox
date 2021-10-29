#include <stdio.h>
#include "includes/intQueue.h"

int main(int argc, char **argv)
{
    QueueList *queue = createQueueIq();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    printf("Peeking: %d\n", peekQ(queue));
    printQueue(queue);
    freeQueue(queue);
    return 0;
}
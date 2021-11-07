#include <stdio.h>
#include <stdlib.h>
#include "../includes/intqueuea.h"

IntQueueA *createIntQueueA(int size);
void freeIntQueueA(IntQueueA *queue);
void enqueueIQA(IntQueueA *queue, int value, int *status)

    int dequeueIQA(IntQueueA *queue, int *status);
int peekIQA(IntQueueA *queue, int *status);
int isEmptyIQA(IntQueueA *queue);
int isFullIQA(IntQueueA *queue);
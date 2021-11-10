#ifndef _intqueuea_h
#define _intqueuea_h

/* The array-backed int queue */

typedef struct _IntQueueA {
    int *queueAry;
    int head;
    int tail;
    int queueSize;
} IntQueueA;

IntQueueA *createIntQueueA(int size);
void freeIntQueueA(IntQueueA *queue);
void enqueueIQA(IntQueueA *queue, int value, int *status);
int dequeueIQA(IntQueueA *queue, int *status);
int peekIQA(IntQueueA *queue, int *status);
int isEmptyIQA(IntQueueA *queue);
int isFullIQA(IntQueueA *queue);

#endif

#ifndef ADTINTLIST_h
#define ADTINTLIST_h

typedef struct _IntList
{
    void *head;
} IntList;

IntList *createIntList();
int sizeIL(IntList *list);
int removeHeadIL(IntList *list, int *status);
int peekIL(IntList *list, int *status);
void prependIL(IntList *list, int value); // contract should not be null
void printIL(IntList *list);
#endif
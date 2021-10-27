#ifndef _intlist_h
#define _intlist_h

typedef struct _IntList
{
    void *head;
} IntList;

// NodeIL *insertNode(NodeIL *head, int value);
// NodeIL *deleteNode(NodeIL *head, int value);
IntList *createIntList();
int sizeIL(IntList *list);
int removeHeadIL(IntList *list, int *status);
int peekIL(IntList *list, int *status);
void prependIL(IntList *list, int value); // contract should not be null
void printIL(IntList *list);
#endif
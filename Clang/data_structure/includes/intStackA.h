#ifndef _intstacka_h
#define _intstacka_h

typedef struct _intStackA
{
    int *stackAry;
    int top;
    int stackSize;
} IntStackA;

IntStackA *createIntStackA(int size);
void freeIntStackA(IntStackA *stack);
void pushISA(IntStackA *stack, int value, int *status);
int popISA(IntStackA *stack, int *status);
int peekISA(IntStackA *stack, int *status);
int isEmptyISA(IntStackA *stack);
int isFullISA(IntStackA *stack);
#endif
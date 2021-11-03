#include "../includes/intStackA.h"
#include <stdlib.h>
#

IntStackA *createIntStackA(int size)
{
    IntStackA *stack = (IntStackA *)malloc(sizeof(IntStackA));
    stack->stackSize = size;
    stack->top = -1;
    stack->stackAry = (int *)malloc(sizeof(int) * size);
    return stack;
};

void freeIntStackA(IntStackA *stack)
{
    free(stack->stackAry);
    free(stack);
};

void pushISA(IntStackA *stack, int value, int *status)
{
    if (isFullISA(stack))
    {
        if (status)
            *status = -1;
        return;
    }
    stack->top++;
    stack->stackAry[stack->top] = value;
    if (status)
        *status = 0;
};

int peekISA(IntStackA *stack, int *status)
{
    int value;
    if (isEmptyISA(stack))
    {
        if (status)
            *status = -2;
        return 0;
    }
    value = stack->stackAry[stack->top];
    if (status)
        *status = 0;
    return value;
};

int popISA(IntStackA *stack, int *status) // may be null status
{
    int value = peekISA(stack, status);
    if (value > 0)
        stack->top--;
    // int value;
    // if (isEmptyISA(stack))
    // {
    //     if (status)
    //         *status = -2;
    //     return 0;
    // }
    // value = stack->stackAry[stack->top];
    // stack->top--;
    // if (status)
    //     *status = 0;
    return value;
};

int isEmptyISA(IntStackA *stack)
{
    return stack->top == -1;
};
int isFullISA(IntStackA *stack)
{
    return stack->top == (stack->stackSize - 1);
};
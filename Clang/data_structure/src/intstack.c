#include "../includes/intstack.h"

IntStack *createIntStackIS()
{
    return createIntList();
}

void pushIS(IntStack *stack, int value)
{
    prependIL(stack, value);
}

int popIS(IntStack *stack, int *status)
{
    return removeHeadIL(stack, status);
}

int isEmptyIS(IntStack *stack)
{
    return !stack->head;
}

int peekIS(IntStack *stack, int *status)
{
    return peekIL(stack, status);
}
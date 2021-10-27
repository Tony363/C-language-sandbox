#ifndef _intstack_h
#define _intstack_h
#include "AdtIntList.h"

typedef IntList IntStack;
IntStack createStackIS(IntStack *stack, int value);
int popIS(IntStack *stack, int *status);
int peekIS(IntStack *stack, int *status);
int isEmptyIS(IntStack *stack);
#endif
#include "includes/intStackA.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    IntStackA *stack;
    int status = 0;
    stack = createIntStackA(5);
    pushISA(stack, 1, &status);
    pushISA(stack, 2, &status);
    pushISA(stack, 3, &status);
    pushISA(stack, 4, &status);

    while (!isEmptyISA(stack))
    {
        int v;
        printf("peek: %d\n", peekISA(stack, NULL));
        v = popISA(stack, NULL);
        printf("popped value: %d\n", v);
    }
    freeIntStackA(stack);
}
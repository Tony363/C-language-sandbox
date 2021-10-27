#include "intlist.h"

int main(int argc, char **argv)
{
    IntList *list;
    list = createIntList();
    prependIL(list, 1);
    prependIL(list, 2);
    prependIL(list, 3);
    prependIL(list, 4);
    prependIL(list, 5);
    printIL(list);
}
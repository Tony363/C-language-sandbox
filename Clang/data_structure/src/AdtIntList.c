#include "../includes/AdtIntList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _NodeIL
{
    int value;
    struct _NodeIL *next;
} NodeIL;

NodeIL *createNodeIL(int value);

NodeIL *createNodeIL(int value)
{
    NodeIL *n;
    n = (NodeIL *)malloc(sizeof(NodeIL));
    n->value = value;
    n->next = NULL;
}

IntList *createIntList()
{
    IntList *list;
    list = (IntList *)malloc(sizeof(IntList));
    list->head = NULL;

    return list;
}

int sizeIL(IntList *list)
{
    if (!(list->head))
        return 0;
    NodeIL *curr;
    int count = 0;
    curr = (NodeIL *)list->head;
    while (curr)
    {
        curr = curr->next;
        count++;
    }
    return count;
}

void prependIL(IntList *list, int value)
{
    NodeIL *n = createNodeIL(value);
    n->next = list->head;
    list->head = n;
}

int removeHeadIL(IntList *list, int *status)
{
    if (!(list->head))
    {
        if (status)
        {
            *status = -1;
        }
        return 0;
    }

    NodeIL *temp;
    int value;
    temp = (NodeIL *)(list->head);
    list->head = temp->next;
    value = temp->value;
    free(temp);
    if (status)
    {
        *status = 0;
    }
    return value;
}

void printIL(IntList *list)
{
    NodeIL *cur;
    cur = list->head;
    printf("[");
    while (cur)
    {
        printf("%d, ", cur->value);
        cur = cur->next;
    }
    printf("]\n");
}

int peekIL(IntList *list, int *status)
{
    if (list->head)
    {
        if (status)
        {
            *status = 0;
        }
        return ((NodeIL *)(list->head))->value;
    }
    else
    {
        if (status)
        {
            *status = -1;
        }
        return 0;
    }
}
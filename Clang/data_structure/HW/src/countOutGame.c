#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Child
{
    int id;
    struct _Child *next;
} Child;

/**
 * Print the children IDs starting from the given first child.
 * @param first The pointer to the first child (may be NULL).
 */
void printChildren(Child *first)
{
    if (!first)
    {
        printf("Children: [ ]\n");
        return;
    }
    else if (first && first->next == first)
    {
        printf("Children: [ %d ]\n", first->id);
        return;
    }
    Child *cur = first->next;
    printf("Children: [ %d ", first->id);
    while (cur != first)
    {
        printf("%d ", cur->id);
        cur = cur->next;
    }
    printf("]\n");
}

/**
 * Remove the m-th child from the circular list.
 * @param first The first child for starting the count.
 * @param m The (positive) count to the target child.
 * @return The pointer to the new first child.
 */
Child *countOut(Child *first, int m)
{
    if (first == NULL || (first != NULL && first->next == first) || m < 0)
        return first;
    if (m == 2)
    {
        Child *tmp = first->next->next;
        free(first->next);
        first->next = tmp;
        return tmp;
    }
    return countOut(first->next, m - 1);
}

Child *linkChildren(int nChild)
{
    if (nChild == 0)
        return NULL;
    if (nChild == 1)
    {
        Child *first = (Child *)malloc(sizeof(Child));
        first->id = 1;
        first->next = first;
        return first;
    }
    Child *first = NULL;
    Child *last = NULL;
    for (int i = 0; i < nChild; i++)
    {
        Child *newChild = (Child *)malloc(sizeof(Child));
        newChild->id = i + 1;
        newChild->next = NULL;
        if (first == NULL)
        {
            first = newChild;
        }
        else
        {
            last->next = newChild;
        }
        last = newChild;
    }
    last->next = first;
    return first;
}

int main(int argc, char **argv)
{
    Child *first = linkChildren(10);
    first = countOut(first, 100);
    printChildren(first);
    return 0;
}
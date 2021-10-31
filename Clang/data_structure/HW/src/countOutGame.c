#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

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
    if (first == NULL || (first != NULL && first->next == first))
        return NULL;
    else if (m == 0)
        return first;
    else if (m == 1)
    {
        Child *tmp = first;
        while (tmp->next != first)
            tmp = tmp->next;
        tmp->next = first->next;
        return first->next;
    }
    Child *cur = first;
    Child *prev = NULL;
    int length = 1;
    while (cur->next != first)
    {
        if (m == length)
        {
            Child *tmp = cur->next;
            prev->next = cur->next;
            free(cur);
            return tmp;
        }
        prev = cur;
        cur = cur->next;
        length++;
    }
    if (m == length && cur->next == first)
    {
        Child *tmp = cur->next;
        prev->next = cur->next;
        free(cur);
        return tmp;
    }
    length = (m - length) % length;
    printf("%d\n", length);
    printChildren(first);
    while (length > 0)
    {
        prev = cur;
        cur = cur->next;
        length--;
    }
    Child *tmp = cur->next;
    prev->next = cur->next;
    free(cur);
    return tmp;
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
    Child *first = linkChildren(4);
    first = countOut(first, 100);
    printChildren(first);
    return 0;
}
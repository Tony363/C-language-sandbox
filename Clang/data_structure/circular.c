#include <stdio.h>
#include "includes/circularlist.h"

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    Node *head = circularList(arr, len);
    printCircular(head);
    Node *five = getCirNode(head, 5);
    printf("%d\n", five->data);
    Node *newHead = add(head, 999);
    printCircular(newHead);
    head = Remove(newHead, 999);
    printCircular(head);
    freeCircular(head);
    return 0;
}
#include <stdio.h>
#include "includes/linklist.h"
#include "includes/circularlist.h"

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    Node *head = circularList(arr, len);
    printCircular(head);
    return 0;
}
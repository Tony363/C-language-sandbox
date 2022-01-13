#include <stdio.h>
#include "includes/circularlist.h"

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    CirList *lst = circularList();
    for (int i = 0; i < len; i++)
        add(lst, arr[i]);
    printf("%d\n", lst->head->data);
    printCircular(lst->head);
    printf("%d\n", getCirNode(lst->head, 5)->data);
    add(lst, 999);
    printCircular(lst->head);
    Remove(lst, 999);
    printCircular(lst->head);
    freeCircular(lst->head);
    return 0;
}
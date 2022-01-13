#include <stdio.h>
#include "includes/doublelist.h"

int main(int argc, char **argv)
{
    int arr[] = {
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
    };
    int len = sizeof(arr) / sizeof(arr[0]);
    DList *lst = createDoubleList();
    for (int i = 0; i < len; i++)
        insertNode(lst, arr[i]);
    print_double_list(lst->head);
    int five;
    printf("%d\n", (five = GetCircular(lst->head, 5)->data) ? five : 9999);

    removeDouble(lst, 0);
    print_double_list(lst->head);
    lst->head = freeCircular(lst->head);
    print_double_list(lst->head);
    return 0;
}
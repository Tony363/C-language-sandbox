#include <stdio.h>
#include "includes/circularlist.h"

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
    Node *head = createDoubleList(arr, len);
    print_double_list(head);
    Node *five = GetCircular(head, 5);
    printf("%d\n", (five) ? five->data : 9999);
    head = insertNode(head, 999);
    print_double_list(head);
    removeDouble(head, 999);
    print_double_list(head);
    head = freeCircular(head);
    print_double_list(head);
    return 0;
}
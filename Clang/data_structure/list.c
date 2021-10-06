#include <stdio.h>
#include "includes/linklist.h"

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(arr) / sizeof(int);
    Node *head = createLinkList(arr, n);
    print_list(head);
    head = insert_node(head, 0, 999);
    print_list(head);
    Node *ninety = get_data(head, 999);
    (!ninety) ? printf("element not found\n") : printf("%d\n", ninety->data);
    head = delete_node(head, 999);
    print_list(head);
    ninety = get_data(head, 999);
    (!ninety) ? printf("element not found\n") : printf("%d\n", ninety->data);
    head = reverse_list(head);
    print_list(head);
    head = freeList(head);
    print_list(head);
    return 0;
}
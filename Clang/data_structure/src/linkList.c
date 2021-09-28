#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node *createLinkList(int data[], int len)
{
    Node *head = createNode(data[0]);
    head->next = NULL;
    Node *node = head;
    int i = 1;
    while (i < len)
    {
        Node *temp = createNode(data[i]);
        node->next = temp;
        node = node->next;
        i++;
    }
    return head;
}

void print_list(Node *node)
{
    while (node)
    {
        printf("%d :", node->data);
        node = node->next;
    }
}

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(arr) / sizeof(int);
    Node *head = createLinkList(arr, n);
    print_list(head);
    return 0;
}
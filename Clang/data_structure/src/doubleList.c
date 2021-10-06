#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
    struct _Node *prev;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node *insertNode(Node *head, int data)
{
    Node *node = createNode(data);
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
    return head;
}
Node *createDoubleList(int arr[], int len)
{
    Node *head = createNode(arr[0]);
    head->prev = NULL;
    head->next = NULL;
    Node *cur = head;
    Node *prev;
    int i = 1;
    while (i < len)
    {
        cur->next = createNode(arr[i]);
        cur->next->prev = cur;
        cur = cur->next;
        i++;
    }
    cur->next = NULL;
    return cur;
}

void print_double_list(Node *head)
{
    Node *temp = head;
    int prev_val = 0;
    while (temp)
    {
        if (temp->next != NULL && prev_val != temp->data)
        {
            printf("%d", temp->data);
            prev_val = temp->data;
            temp = temp->next;
        }
        else
        {
            printf("%d", temp->data);
            prev_val = temp->data;
            temp = temp->prev;
        }
    }
}

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
    return 0;
}
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
    return head;
}

Node *GetCircular(Node *head, int data)
{
    Node *temp = head;
    int next = 0, prev = 0;
    if (temp->next)
        next = 1;
    else
        prev = 1;

    while (temp)
    {
        if (temp->data == data)
        {
            return temp;
        }
        if (next == 1)
            temp = temp->next;
        else
            temp = temp->prev;
    }
    return NULL;
}

// need to counter for last node and first node
Node *removeDouble(Node *head, int val)
{
    if (!head || !head->next)
    {
        return NULL;
    }
    else if (head->data == val)
    {
        Node *temp = head;
        // printf("wtf: %d\n", head->data);
        head = head->next;
        head->prev = NULL;
        // printf("wtf: %d\n", head->data);
        free(temp);
        return head;
    }
    Node *temp = head;
    int next = 0, prev = 0;
    if (temp->next)
        next = 1;
    else
        prev = 1;
    while (temp)
    {
        if (temp->data == val)
        {
            if (temp->prev)
            {
                temp->prev->next = temp->next;
            }
            if (temp->next)
            {
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
        if (next == 1) // going backwards or forwards
            temp = temp->next;
        else
            temp = temp->prev;
    }
    return head;
}

void print_double_list(Node *head)
{
    Node *temp = head;
    int next = 0, prev = 0;
    if (temp && temp->next)
        next = 1;
    else
        prev = 1;

    printf("[");
    while (temp)
    {
        if (next == 1)
        {
            printf("%d,", temp->data);
            temp = temp->next;
        }
        else
        {
            printf("%d,", temp->data);
            temp = temp->prev;
        }
    }
    printf("]\n");
}

Node *freeCircular(Node *head)
{
    Node *cur = head;
    Node *temp;
    int next = 0, prev = 0;
    if (cur->next)
        next = 1;
    else
        prev = 1;
    while (cur)
    {
        // printf("%d ", cur->data);

        if (next == 1)
        {
            temp = cur;
            cur = cur->next;
            free(temp);
        }
        else
        {
            temp = cur;
            cur = cur->prev;
            free(temp);
        }
    }
    return NULL;
}

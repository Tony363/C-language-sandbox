#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int length(Node *linkList)
{
    int len = 0;
    Node *node = linkList;
    while (node)
    {
        len++;
        node = node->next;
    }
    return len;
}

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node *circularList(int data[], int len)
{
    Node *head = createNode(data[0]);
    Node *node = head;
    int i = 1;
    while (i < len)
    {
        Node *temp = createNode(data[i]);
        node->next = temp;
        node = node->next;
        i++;
    }
    node->next = head;
    return head;
}

void printCircular(Node *head)
{
    Node *temp = head;
    printf("[");
    while (temp->next != head)
    {
        printf("%d ,", temp->data);
        temp = temp->next;
    }
    printf("%d ,", temp->data);
    printf("]\n");
}

Node *getCirNode(Node *head, int data)
{
    Node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    if (temp->data == data)
        return temp;
    return NULL;
}

Node *add(Node *head, int data)
{
    Node *new = createNode(data);
    Node *temp = head->next;
    head->next = new;
    new->next = temp;
    return head;
}

Node *Remove(Node *head, int data)
{
    Node *cur = head;
    Node *prev = NULL;
    Node *last = NULL;
    while (cur->next != head)
    {
        if (cur->data == data)
        {
            prev->next = cur->next;
            free(cur);
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    if (head == cur && cur->data == data)
    {
        while (cur->next != head)
            cur = cur->next;
        last = cur;
        last->next = head->next;
        return head->next;
    }
    else
    {
        prev->next = head;
    }
    return head;
}

Node *freeCircular(Node *head)
{
    Node *cur = head;
    Node *prev = NULL;
    while (cur->next != head)
    {
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    free(cur);
    return NULL;
}
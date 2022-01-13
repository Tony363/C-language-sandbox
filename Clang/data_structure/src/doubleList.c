#include <stdio.h>
#include <stdlib.h>
#include "../includes/doublelist.h"

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insertNode(DList *lst, int data)
{
    Node *node = createNode(data);
    if (!lst->head)
    {
        lst->head = node;
        lst->tail = node;
        return;
    }
    else
    {
        Node *temp = lst->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
}

DList *createDoubleList()
{
    DList *list = (DList *)malloc(sizeof(DList));
    list->head = NULL;
    list->tail = NULL;
    return list;
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
void removeDouble(DList *lst, int data)
{
    if (!lst || !lst->head)
        return;
    Node *temp = lst->head;
    if (temp->data == data)
    {
        lst->head = temp->next;
        free(temp);
        return;
    }
    while (temp)
    {
        if (temp->data == data)
        {
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            else
                lst->tail = temp->prev;
        }
        temp = temp->next;
    }
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

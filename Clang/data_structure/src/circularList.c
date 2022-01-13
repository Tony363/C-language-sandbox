#include <stdio.h>
#include <stdlib.h>
#include "../includes/circularlist.h"

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

CirList *circularList()
{
    CirList *list = (CirList *)malloc(sizeof(CirList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void printCircular(Node *head)
{
    if (!head)
        return;
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

void add(CirList *lst, int data)
{
    Node *new = createNode(data);
    if (!lst->head)
    {
        lst->head = new;
        lst->tail = new;
        new->next = lst->head;
        return;
    }
    lst->tail->next = new;
    new->next = lst->head;
    lst->head = new;
}

void Remove(CirList *lst, int data)
{
    if (!lst)
        return;
    if (lst->head->data == data)
    {
        Node *tmp = lst->head;
        lst->tail->next = lst->head->next;
        lst->head = lst->head->next;
        free(tmp);
        return;
    }
    Node *tmp = lst->head;
    while (tmp->next != lst->head)
    {
        if (tmp->next->data == data)
        {
            Node *tmp2 = tmp->next;
            tmp->next = tmp->next->next;
            free(tmp2);
            return;
        }
        tmp = tmp->next;
    }
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
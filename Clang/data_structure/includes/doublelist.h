#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

typedef struct _Node
{
    int data;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct DList
{
    Node *head;
    Node *tail;
} DList;

DList *createDoubleList();
Node *createNode(int data);
void insertNode(DList *lst, int data);
Node *GetCircular(Node *head, int data);
void removeDouble(DList *lst, int data);
void print_double_list(Node *head);
Node *freeCircular(Node *head);
#endif
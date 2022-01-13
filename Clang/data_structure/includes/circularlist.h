#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct CirList
{
    Node *head;
    Node *tail;
} CirList;

CirList *circularList();
Node *createNode(int data);
void printCircular(Node *head);
Node *getCirNode(Node *head, int data);
void add(CirList *lst, int data);
void Remove(CirList *lst, int data);
Node *freeCircular(Node *head);

#endif
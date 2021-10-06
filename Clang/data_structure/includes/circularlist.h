#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
Node *insertCircular(Node *head, int index, int data);
Node *circularList(int data[], int len);
Node *getCirNode(Node *head, int data);
Node *add(Node *head, int data);
Node *Remove(Node *head, int data);
Node *freeCircular(Node *head);
void printCircular(Node *head);
#endif
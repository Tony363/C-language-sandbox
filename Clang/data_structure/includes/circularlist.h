#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
// #include "linklist.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
Node *insertCircular(Node *head, int index, int data);
Node *circularList(int data[], int len);
void printCircular(Node *head);
#endif
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
Node *insertNode(Node *head, int data);
Node *createDoubleList(int arr[], int len);
Node *GetCircular(Node *head, int data);
Node *removeDouble(Node *head, int val);
void print_double_list(Node *head);
Node *freeCircular(Node *head);
#endif
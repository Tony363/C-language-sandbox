#ifndef LINKLIST_H
#define LINKLIST_H
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *createNode(int data);
Node *createLinkList(int data[], int len);
Node *freeList(Node *head);
void print_list(Node *node);
void freeNode(Node *node);
int length(Node *linkList);
Node *insert_node(Node *linkedList, int index, int data);
Node *get_data(Node *linkedList, int data);
Node *delete_node(Node *linkedList, int data);
Node *reverse_list(Node *linkedList);
#endif
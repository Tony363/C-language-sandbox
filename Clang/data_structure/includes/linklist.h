#ifndef LISTLIST_H
#define LISTLIST_H
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *createNode(int data);
Node *createLinkList(int data[], int len);
void print_list(Node *node);
int length(Node *linkList);
Node *insert_node(Node *linkedList, int index, int data);
Node *get_data(Node *linkedList, int data);
Node *delete_node(Node *linkedList, int data);
Node *reverse_list(Node *linkedList);
Node *freeList(Node *head);
int getValueIl(int *head, int index, int *status_code);

#endif
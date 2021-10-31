
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node *createLinkList(int data[], int len)
{
    Node *head = createNode(data[0]);
    head->next = NULL;
    Node *node = head;
    int i = 1;
    while (i < len)
    {
        Node *temp = createNode(data[i]);
        node->next = temp;
        node = node->next;
        i++;
    }
    return head;
}

void print_list(Node *node)
{
    Node *temp = node;
    printf("[");
    while (temp)
    {
        printf("%d ,", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

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

Node *insert_node(Node *linkedList, int index, int data)
{
    Node *temp = createNode(data);
    Node *head = linkedList;
    if (!head)
        return temp;

    int len = length(linkedList);
    if (index == 0)
    {
        temp->next = head;
        return temp;
    }
    int i = 0;
    while ((index > 0 && i <= index) || ((index < 0) && (len + index) >= index))
    {
        if (!head)
        {
            printf("Index out of bound\n");
            return linkedList;
        }
        if ((index > 0 && i == index) || ((index < 0) && ((len + index) == i)))
        {
            Node *afterInsert = head->next;
            head->next = temp;
            temp->next = afterInsert;
            break;
        }
        head = head->next;
        i++;
    }
    return linkedList;
}

Node *get_data(Node *linkedList, int data)
{
    Node *temp = linkedList;
    while (temp && temp->data != data)
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    (!temp) ? printf("element not found\n") : printf("%d\n", temp->data);
    return NULL;
}

Node *delete_node(Node *linkedList, int data)
{
    Node *temp = linkedList;
    Node *prev = temp;
    while (temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == data && prev == temp)
    {
        linkedList = temp->next;
        free(temp);
    }
    else if (temp->data == data)
    {
        prev->next = temp->next;
        free(temp);
    }
    return linkedList;
}

Node *reverse_list(Node *linkedList)
{
    Node *current = linkedList;
    if (!current)
        return NULL;

    Node *prev = NULL, *temp = NULL;
    while (current)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

void freeNode(Node *node)
{
    free(node);
}

Node *freeList(Node *head)
{
    Node *temp = NULL;
    Node *cur = head;
    while (cur)
    {
        temp = cur->next;
        freeNode(cur);
        cur = temp;
    }
    return NULL;
}

int getValueIl(int *head, int index, int *status_code)
{
    int i;
    Node *cur = head;
    if (!head || index < 0)
    {
        // invalid index return
        if (status_code)
            *status_code = -1;
        return 0;
    }
    for (i = 0; i < index; i++)
    {
        if (!cur && i != index)
            break;
        cur = cur->next;
    }
    if (i < index)
    {
        if (status_code)
            *status_code = -1;
        return 0;
    }
    if (status_code)
        *status_code = 0;
    return cur->data;
}
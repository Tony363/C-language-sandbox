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
        temp = temp->next;
    if (temp && temp->data == data)
        return temp;
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

/*FIX ME have no idea how to completely free a node*/
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
    return head;
}

// void freeList(Node *currentNode)
// {
//     if (currentNode->next)
//         freeList(currentNode->next);
//     free(currentNode);
// }
int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(arr) / sizeof(int);
    Node *head = createLinkList(arr, n);
    print_list(head);
    head = insert_node(head, 0, 999);
    print_list(head);
    Node *ninety = get_data(head, 999);
    (!ninety) ? printf("element not found\n") : printf("%d\n", ninety->data);
    head = delete_node(head, 999);
    print_list(head);
    ninety = get_data(head, 999);
    (!ninety) ? printf("element not found\n") : printf("%d\n", ninety->data);
    head = reverse_list(head);
    print_list(head);
    head = freeList(head);
    print_list(head);
    return 0;
}
#include <stdio.h>
#include "../includes/linklist.h"

Node *circularList(int data[], int len)
{
    Node *head = createNode(data[0]);
    Node *node = head;
    int i = 1;
    while (i < len)
    {
        Node *temp = createNode(data[i]);
        node->next = temp;
        node = node->next;
        i++;
    }
    node->next = head;
    return head;
}

void printCircular(Node *head)
{
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

// Node *insertCircular(Node *head, int index, int data)
// {
//     Node *temp = createNode(data);
//     Node *cur = head;
//     int len = length(head);
//     if (index == 0)
//     {
//         temp->next = head;
//         return temp;
//     }
//     int i = 0;
//     while ((index > 0 && i <= index) || ((index < 0) && (len + index) >= index))
//     {
//         if (!cur)
//         {
//             printf("Index out of bound\n");
//             return head;
//         }
//         if ((index > 0 && i == index) || ((index < 0) && ((len + index) == i)))
//         {
//             Node *afterInsert = cur->next;
//             cur->next = temp;
//             temp->next = afterInsert;
//             break;
//         }
//         cur = cur->next;
//         i++;
//     }
//     return head;
// }
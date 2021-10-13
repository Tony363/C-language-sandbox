// C program for generic linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*USE uint_8*/

typedef struct _Node
{
    void *data;
    struct _Node *next;
} Node;

Node *createIntLinkList(Node *start, int *arr, int len);
Node *createDoubleLinkList(Node *start, double *arr, int len);

void push(Node **head_ref, void *new_data, size_t data_size)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = malloc(data_size);
    new_node->next = (*head_ref);
    memcpy(new_node->data, new_data, data_size);

    (*head_ref) = new_node;
}

void printList(Node *node, void (*fptr)(void *))
{
    while (node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}

void printInt(void *n)
{
    printf(" %d", *(int *)n);
    printf("\n");
}

void printFloat(void *f)
{
    printf(" %lf", *(double *)f);
    printf("\n");
}

Node *createIntNode(int *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = malloc(sizeof(int));
    memcpy(node->data, data, sizeof(int));
    node->next = NULL;
    return node;
}

Node *createDoubleNode(double *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = malloc(sizeof(double));
    memcpy(node->data, data, sizeof(double));
    node->next = NULL;
    return node;
}

Node *createADTLinkList(Node *start, void *arr, int len, size_t data_size)
{
    if (data_size == sizeof(int))
        start = createIntLinkList(start, (int *)arr, len);
    else if (data_size == sizeof(double))
        start = createDoubleLinkList(start, (double *)arr, len);
    return start;
}

Node *createIntLinkList(Node *start, int *arr, int len)
{
    start = createIntNode(arr);
    start->next = NULL;
    Node *node = start;
    int i = 1;
    while (i < len)
    {
        Node *temp = createIntNode((arr + i));
        node->next = temp;
        node = node->next;
        i++;
    }
    return start;
}

Node *createDoubleLinkList(Node *start, double *arr, int len)
{
    start = createDoubleNode(&arr[0]);
    start->next = NULL;
    Node *node = start;
    int i = 1;
    while (i < len)
    {
        Node *temp = createDoubleNode((arr + i));
        node->next = temp;
        node = node->next;
        i++;
    }
    return start;
}

int getADTLength(Node *start, int count)
{
    if (!start)
        return count;
    count += 1;
    return getADTLength(start->next, count);
}

Node *containsIntValue(Node *start, int target)
{
    if (!start)
        return NULL;
    else if (*(int *)(start->data) == target)
        return start;
    return containsIntValue(start->next, target);
}

Node *containsDoubleValue(Node *start, double target)
{
    if (!start)
        return NULL;
    else if (*(double *)(start->data) == target)
        return start;
    return containsDoubleValue(start->next, target);
}

Node *containsValue(Node *start, void *target, size_t data_size)
{
    Node *node = start;
    if (data_size == sizeof(int))
        node = containsIntValue(node, *(int *)target);
    else if (data_size == sizeof(double))
        node = containsDoubleValue(node, *(double *)target);
    return node;
}

Node *insertInt(Node *start, int index, int *data)
{
    Node *temp = createIntNode(data);
    Node *head = start;
    int len = getADTLength(start, 0);
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
            return start;
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
    return start;
}

Node *insertDouble(Node *start, int index, double *data)
{
    Node *temp = createDoubleNode(data);
    Node *head = start;
    int len = getADTLength(start, 0);
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
            return start;
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
    return start;
}

Node *insertNode(Node *start, int index, void *data, size_t data_size)
{
    Node *node = start;
    if (data_size == sizeof(int))
        node = insertInt(node, index, ((int *)data));
    else if (data_size == sizeof(double))
        node = insertDouble(node, index, ((double *)data));
    return node;
}

Node *deleteInt(Node *linkedList, int data)
{
    Node *temp = linkedList;
    Node *prev = temp;
    while (*(int *)(temp->data) != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (*(int *)(temp->data) == data && prev == temp)
    {
        linkedList = temp->next;
        free(temp);
    }
    else if (*(int *)(temp->data) == data)
    {
        prev->next = temp->next;
        free(temp);
    }
    return linkedList;
}

Node *deleteDouble(Node *linkedList, double data)
{
    Node *temp = linkedList;
    Node *prev = temp;
    while (*(double *)(temp->data) != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (*(double *)(temp->data) == data && prev == temp)
    {
        linkedList = temp->next;
        free(temp);
    }
    else if (*(double *)(temp->data) == data)
    {
        prev->next = temp->next;
        free(temp);
    }
    return linkedList;
}

Node *deleteNode(Node *start, void *data, size_t data_size)
{
    Node *node = start;
    if (data_size == sizeof(int))
        node = deleteInt(node, *((int *)data));
    else if (data_size == sizeof(double))
        node = deleteDouble(node, *((double *)data));
    return node;
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
    return NULL;
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

/* Driver program to test above function */
int main()
{
    Node *start = NULL;

    // Create and print an int linked list
    unsigned int_size = sizeof(int);
    int arr[] = {10, 20, 30, 40, 50};
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    start = createADTLinkList(start, arr, arrlen, int_size);
    printf("Created integer linked list is \n");
    printList(start, printInt);
    printf("Length of %d\n", getADTLength(start, 0));
    int ten = 10;
    Node *tenNode = containsValue(start, &ten, sizeof(ten));
    (ten) ? printf("FOUND: %d\n", *(int *)(tenNode->data)) : printf("not found\n");

    int inVal = 999;
    start = insertNode(start, -1, &inVal, sizeof(inVal));
    printList(start, printInt);
    start = deleteNode(start, &inVal, sizeof(inVal));
    printList(start, printInt);
    start = freeList(start);

    // Create and print a float linked list
    unsigned float_size = sizeof(double);
    start = NULL;
    double arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};
    int arrlen2 = sizeof(arr2) / sizeof(arr2[0]);
    start = createADTLinkList(start, arr2, arrlen2, float_size);
    printf("\n\nCreated float linked list is \n");
    printList(start, printFloat);
    printf("Length of %d\n", getADTLength(start, 0));
    double tenDec = 40.400002;
    Node *tenDecNode = containsValue(start, &tenDec, sizeof(tenDec));
    (tenDecNode) ? printf("FOUND: %lf\n", *(double *)(tenDecNode->data)) : printf("not found\n");
    double dinVal = 999.9;
    start = insertNode(start, -1, &dinVal, sizeof(dinVal));
    printList(start, printFloat);
    start = deleteNode(start, &dinVal, sizeof(dinVal));
    printList(start, printFloat);
    start = reverse_list(start);
    printList(start, printFloat);
    start = freeList(start);
    printList(start, printFloat);
    return 0;
}
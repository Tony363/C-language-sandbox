#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

typedef struct _Stack
{
    Node *head;
    char status_code[20];
} Stack;

Node *createNode(int data)
{
    if (!data)
        return NULL;
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void push(Stack *stack, int data)
{
    Node *new = createNode(data);
    if (stack->head)
        new->next = stack->head;
    stack->head = new;
}

int isEmpty(Node *head, Stack *stack)
{
    if (!head)
    {
        strcpy(stack->status_code, "Empty");
        return 1;
    }
    strcpy(stack->status_code, "Not Empty");
    return 0;
}

int pop(Stack *stack)
{
    Node *cur = stack->head;
    if (isEmpty(stack->head, stack))
        return -1;

    int val = cur->data;
    stack->head = cur->next;
    free(cur);
    return val;
}

Stack *createStack(int *arr, int len)
{
    if (!arr)
        return NULL;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    int i = 0;
    while (i < len)
    {
        push(stack, arr[i]);
        i++;
    }
    char *notEmpty = "Not Empty";
    strcpy(stack->status_code, notEmpty);
    return stack;
}

int getLen(Node *head)
{
    int i = 0;
    while (head)
    {
        i++;
        head = head->next;
    }
    return i;
}

int peek(Node *head)
{
    if (!head)
    {
        return 9999;
    }
    while (head->next)
        head = head->next;
    return head->data;
}

void printStack(Stack *stack)
{
    Node *cur = stack->head;
    printf("[");
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("]\n");
}

Node *freeStack(Node *head)
{
    Node *temp;
    while (head->next)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    return NULL;
}

int main(int argc, char **argv)
{
    char *status_code = "";
    int stackLen = 5;
    int arr[] = {1, 2, 3, 4, 5};
    Stack *stack = createStack(arr, stackLen);
    printf("%s\n", stack->status_code);
    printStack(stack);
    for (int i = 0; i < stackLen; i++)
    {
        printf("popped %d\n", pop(stack));
    }
    printStack(stack);
    // push(head, 6);
    // push(head, 7);
    // push(head, 8);
    // push(head, 9);
    // push(head, 10);

    // printStack(head);
    // stackLen = getLen(head);

    // head = createStack(arr, 5);
    // printStack(head);
    // head = freeStack(head);

    return 0;
}
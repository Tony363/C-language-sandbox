#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

typedef struct _Stack
{
    Node *top;
} Stack;

void *push(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

int isEmpty(Stack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    int n, i;
    printf("Enter the number to convert: ");
    scanf("%d", &n);
    int Q = n, R;
    while (Q != 0)
    {
        R = Q % 2;
        push(s, R);
        Q = Q / 2;
    }
    printf("\nBinary of Given Number is=");
    while (!isEmpty(s))
    {
        printf("%d", pop(s));
    }
    return 0;
}
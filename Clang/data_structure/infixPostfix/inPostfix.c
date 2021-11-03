#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Cnode
{
    char c;
    struct _Cnode *next;
} Cnode;

typedef struct _Queue
{
    Cnode *front;
    Cnode *rear;
} Queue;

typedef struct _Stack
{
    Cnode *head;
} Stack;

typedef struct _Output
{
    char type;
    union
    {
        Queue *operandQ;
        Stack *operatorS;
    } QorS;
} Output;

Cnode *createCnode(char c)
{
    Cnode *new = (Cnode *)malloc(sizeof(Cnode));
    new->c = c;
    new->next = NULL;
    return new;
}

Stack *push(Stack *stack, char c)
{
    Cnode *new = createCnode(c);
    if (stack->head == NULL)
    {
        stack->head = new;
        return stack;
    }
    new->next = stack->head;
    stack->head = new;
    return stack;
}

Queue *enqueue(Queue *q, char c)
{
    Cnode *new = createCnode(c);
    if (q->front == NULL)
    {
        q->front = q->rear = new;
        return q;
    }
    q->rear->next = new;
    q->rear = q->rear->next;
    return q;
}

Queue *dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    Cnode *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return q;
}

Queue *toQueue(char *string)
{
    if (!string)
        return NULL;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q = enqueue(q, *(string));
    int i = 1;
    while (*(string + i) != '\0')
    {
        q = enqueue(q, *(string + i));
        i++;
    }
    return q;
}

char peek(Output *output)
{
    if (output->type == '0' && (output->QorS).operatorS->head != NULL)
        return (output->QorS).operatorS->head->c;
    else if (output->type == '1' && (output->QorS).operandQ->front != NULL)
        return (output->QorS).operandQ->front->c;
    return ' ';
}

char pop(Output *output)
{
    char c;
    Cnode *head;
    if (output->type == '0' && (output->QorS).operatorS->head != NULL)
    {

        c = peek(output);
        head = (output->QorS).operatorS->head;
        (output->QorS).operatorS->head = head->next;
        free(head);
        return c;
    }
    else if (output->type == '1' && (output->QorS).operandQ->front != NULL)
    {
        head = (output->QorS).operandQ->front;
        c = peek(output);
        head = head->next;
        return c;
    }
    return ' ';
}

void print(Output *list)
{
    Cnode *temp;
    if (list->type == '1')
        temp = (list->QorS).operandQ->front;
    else if (list->type == '0')
        temp = (list->QorS).operatorS->head;
    while (temp != NULL)
    {
        printf("%c", temp->c);
        temp = temp->next;
    }
    printf("\n");
}

int isOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || '(' || ')')
        return 0;
    return 1;
}

int isEmpty(Output *output)
{
    if (output->type == '1')
        return (output->QorS).operandQ->front == NULL;
    else if (output->type == '2')
        return (output->QorS).operatorS->head == NULL;
    return 0;
}

int checkPrecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

void toPostfix(char *str)
{
    Output *operandQ = (Output *)malloc(sizeof(Queue));
    operandQ->type = '1';
    operandQ->QorS.operandQ = (Queue *)malloc(sizeof(Queue));
    Output *operatorS = (Output *)malloc(sizeof(Stack));
    operatorS->type = '0';
    operatorS->QorS.operatorS = (Stack *)malloc(sizeof(Stack));

    int i = 0;
    char tmp;
    while (*(str + i) != '\0')
    {
        if (isOperand(*(str + i)))
        {
            printf("%c", *(str + i));
        }
        else if (*(str + i) == '(')
        {
            (operatorS->QorS).operatorS = push((operatorS->QorS).operatorS, *(str + i));
        }
        else if (*(str + i) == ')')
        {
            while (peek(operatorS) != '(')
            {
                printf("%c", pop(operatorS));
            }
        }
        else if (!isOperand(*(str + i)))
        {
            while (peek(operatorS) != ' ' && peek(operatorS) != '(' && (checkPrecedence(*(str + i)) >= checkPrecedence(peek(operatorS))))
            {
                printf("%c", pop(operatorS));
            }
            (operatorS->QorS).operatorS = push((operatorS->QorS).operatorS, *(str + i));
        }
        i++;
    }
    // print(output->operandQ);
    // print(output->operatorS);
}

int main(int argc, char **argv)
{
    char *str = "1 + 2";
    // Queue *q = toQueue(str);
    // print(q);
    toPostfix(str);
    // Output *output = (Output *)malloc(sizeof(Output));
    // output->operandQ = (Queue *)malloc(sizeof(Queue));
    // output->operatorS = (Stack *)malloc(sizeof(Stack));
    // output->operatorS = push(output->operatorS, '(');
    // output->operatorS = push(output->operatorS, '1');
    // output->operatorS = push(output->operatorS, '+');
    // output->operatorS = push(output->operatorS, '1');
    // output->operatorS = push(output->operatorS, ')');
    // print(output->operatorS);
    return 0;
}
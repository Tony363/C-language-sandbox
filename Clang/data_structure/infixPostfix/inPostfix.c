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
        return NULL;
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
        printf("PRINT: %c\n", temp->c);
        temp = temp->next;
    }
    printf("\n\n");
}

int isOperand(char c)
{
    return !(
        c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '(' || c == ')');
}

int isEmpty(Output *output)
{
    if (output->type == '1')
        return (output->QorS).operandQ->front == NULL;
    else if (output->type == '0')
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
/*
write string to  bin file then read from bin, side byte size,convert to string, eval
output is queue
1*2+3
*/
Output *toPostfix(char *str)
{
    Output *operatorS = (Output *)malloc(sizeof(Output));
    operatorS->type = '0';
    operatorS->QorS.operatorS = (Stack *)malloc(sizeof(Stack));
    Output *operandQ = (Output *)malloc(sizeof(Output));
    operandQ->type = '1';
    operandQ->QorS.operandQ = (Queue *)malloc(sizeof(Queue));

    int i = 0;
    size_t size = 0;
    char p;
    while (*(str + i) != '\0')
    {
        if (*(str + i) == ' ')
        {
            i++;
            continue;
        }
        else if (isOperand(*(str + i)))
        {
            (operandQ->QorS).operandQ = enqueue(operandQ->QorS.operandQ, *(str + i));
            printf("%c", *(str + i));
        }
        else if (*(str + i) == '(')
        {
            (operatorS->QorS).operatorS = push((operatorS->QorS).operatorS, *(str + i));
        }
        else if (*(str + i) == ')')
        {

            while (p = pop(operatorS))
            {
                if (p == '(')
                    break;
                (operandQ->QorS).operandQ = enqueue(operandQ->QorS.operandQ, p);
                printf("%c", p);
            }
        }
        else
        {
            while (!isEmpty(operatorS) && peek(operatorS) != '(' && (checkPrecedence(*(str + i)) <= checkPrecedence(peek(operatorS))))
            {
                p = pop(operatorS);
                (operandQ->QorS).operandQ = enqueue(operandQ->QorS.operandQ, p);
                printf("%c", p);
            }
            (operatorS->QorS).operatorS = push((operatorS->QorS).operatorS, *(str + i));
        }
        i++;
    }
    while (!isEmpty(operatorS))
    {
        if (peek(operatorS) == '(' || peek(operatorS) == ')')
            pop(operatorS);
        p = pop(operatorS);
        (operandQ->QorS).operandQ = enqueue(operandQ->QorS.operandQ, p);
        printf("%c", p);
    }
    return operandQ;
}

char eval(Output *stack, char operator)
{
    int op1 = pop(stack) - '0';
    int op2 = pop(stack) - '0';
    int result = 0;
    switch (operator)
    {
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op2 - op1;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '/':
        result = op2 / op1;
        break;
    }
    printf("result: %d%c%d=%d\n", op1, operator, op2, result);
    return result + '0';
}

char evaluatePostfix(Output *expr)
{
    Output *operatorS = (Output *)malloc(sizeof(Output));
    operatorS->type = '0';
    operatorS->QorS.operatorS = (Stack *)malloc(sizeof(Stack));

    int i = 0;
    while (!isEmpty(expr))
    {
        // printf("%c\n", (expr->QorS).operandQ->front->c);
        if (isOperand(peek(expr)))
        {
            printf("pushing: %c\n", peek(expr));
            operatorS->QorS.operatorS = push(operatorS->QorS.operatorS, peek(expr));
        }
        else
        {
            char result = eval(operatorS, peek(expr));
            printf("pushing: %c\n", result);
            operatorS->QorS.operatorS = push(operatorS->QorS.operatorS, result);
        }
        (expr->QorS).operandQ = dequeue((expr->QorS).operandQ);
    }

    return pop(operatorS);
}

int main(int argc, char **argv)
{
    char *str = "(7 - 3) * (9 - 8) / 4";
    Output *postfix = toPostfix(str);
    printf("\n");
    print(postfix);
    char *expr = "73-98-*4/";
    printf("%c\n", evaluatePostfix(postfix));
    return 0;
}
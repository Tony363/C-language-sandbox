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
        printf("%c", temp->c);
        temp = temp->next;
    }
    printf("\n");
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

char *toPostfix(char *str)
{
    Output *operatorS = (Output *)malloc(sizeof(Output));
    operatorS->type = '0';
    operatorS->QorS.operatorS = (Stack *)malloc(sizeof(Stack));

    int i = 0;
    size_t size = 0;
    char tmp;
    char *postfix = NULL;
    while (*(str + i) != '\0')
    {
        if (*(str + i) == ' ')
        {
            i++;
            continue;
        }
        else if (isOperand(*(str + i)))
        {
            size = i + 1;
            postfix = (char *)realloc(postfix, size);
            *(postfix + i) = *(str + i);
            printf("%c", *(str + i));
        }
        else if (*(str + i) == '(')
        {
            (operatorS->QorS).operatorS = push((operatorS->QorS).operatorS, *(str + i));
        }
        else if (*(str + i) == ')')
        {
            char p;
            while (p = pop(operatorS))
            {
                if (p == '(')
                    break;
                size = i + 1;
                postfix = (char *)realloc(postfix, size);
                *(postfix + i) = p;
                printf("%c", p);
            }
        }
        else
        {
            while (!isEmpty(operatorS) && peek(operatorS) != '(' && (checkPrecedence(*(str + i)) <= checkPrecedence(peek(operatorS))))
            {
                size = i + 1;
                postfix = (char *)realloc(postfix, size);
                *(postfix + i) = pop(operatorS);
                printf("%c", *(postfix + i));
            }
            (operatorS->QorS).operatorS = push((operatorS->QorS).operatorS, *(str + i));
        }
        i++;
    }
    while (!isEmpty(operatorS))
    {
        if (peek(operatorS) == '(' || peek(operatorS) == ')')
            pop(operatorS);
        size = i + 1;
        postfix = (char *)realloc(postfix, size);
        *(postfix + i) = pop(operatorS);
        printf("%c", *(postfix + i));
    }
    size = i + 1;
    postfix = (char *)realloc(postfix, size);
    *(postfix + i++) = '\0';
    return postfix;
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

int evaluatePostfix(char *expr)
{
    Output *operatorS = (Output *)malloc(sizeof(Output));
    operatorS->type = '0';
    operatorS->QorS.operatorS = (Stack *)malloc(sizeof(Stack));

    int i = 0;
    while (*(expr + i) != '\0')
    {
        if (isOperand(*(expr + i)))
        {
            printf("pushing: %c\n", *(expr + i));
            operatorS->QorS.operatorS = push(operatorS->QorS.operatorS, *(expr + i));
        }
        else
        {
            char result = eval(operatorS, *(expr + i));
            printf("pushing: %c\n", result);
            operatorS->QorS.operatorS = push(operatorS->QorS.operatorS, result);
        }
        i++;
    }
    return pop(operatorS) - '0';
}

int main(int argc, char **argv)
{
    char *str = "(7 - 3) * (9 - 8) / 4";
    char *postfix = toPostfix(str);
    // printf("%c\n", *(postfix + 0));
    char *expr = "73-98-*4/";
    printf("%d\n", evaluatePostfix(expr));
    return 0;
}
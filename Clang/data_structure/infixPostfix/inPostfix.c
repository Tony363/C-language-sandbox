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

Cnode *createCnode(char c)
{
    Cnode *new = (Cnode *)malloc(sizeof(Cnode));
    new->c = c;
    new->next = NULL;
    return new;
}

Queue *enqueue(Queue *q, char c)
{
    Cnode *new = createCnode(c);
    if (q->front == NULL)
    {
        q->front = new;
        q->rear = new;
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

void printQ(Queue *q)
{
    Cnode *temp = q->front;
    while (temp != NULL)
    {
        printf("%c", temp->c);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    char *str = "1 + 1";
    Queue *q = toQueue(str);
    printQ(q);
    return 0;
}
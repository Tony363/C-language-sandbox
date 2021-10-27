#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isEmpty(int front, int rear)
{
    if (front == rear)
        return 1;
    else
        return 0;
}

int *enqueue(int arr[], int *front, int *rear, int maxsize, int item)
{
    if (isEmpty((*rear + 1) % maxsize, *front))
    {
        printf("Queue Overflow\n");
        return arr;
    }
    else
    {
        arr[*rear] = item;
        *rear = (*rear + 1) % maxsize;
        return arr;
    }
}

int *dequeue(int arr[], int *front, int *rear, int *dvalue, int maxsize)
{
    if (isEmpty(*front, *rear))
    {
        printf("Queue Underflow\n");
        return arr;
    }
    else
    {
        *dvalue = arr[*front];
        *front = (*front + 1) % maxsize;
        return arr;
    }
}

void printQueue(int arr[], int front, int maxsize, int rear)
{
    int i;
    if (isEmpty(front, rear))
        printf("Queue is Empty\n");
    else
        for (i = front; i != rear; i = (i + 1) % maxsize)
            printf("%d ", arr[i]);
    printf("\n", arr[i]);
}

int main(int argc, char **argv)
{
    int front = 0, rear = 0, size = 5, value = 0;
    int arr[] = {0, 0, 0, 0, 0};
    memcpy(arr, enqueue(arr, &front, &rear, size, 1), sizeof(int) * size);
    memcpy(arr, enqueue(arr, &front, &rear, size, 2), sizeof(int) * size);
    printQueue(arr, front, size, rear);
    memcpy(arr, dequeue(arr, &front, &rear, &value, size), sizeof(int) * size);
    printf("dequeued value: %d\n", value);
    printQueue(arr, front, size, rear);
    return 0;
}
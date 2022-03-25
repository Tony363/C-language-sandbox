#include <stdio.h>
#include <math.h>

double getAvg(int *arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / (double)size;
}

double getStd(int *arr, int size)
{
    double avg = getAvg(arr, size);
    double std = 0;
    for (int i = 0; i < size; i++)
    {
        std += pow(arr[i] - avg, 2);
    }
    return sqrt(std / (size));
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "includes/quicksort.h"
#include "includes/bubblesort.h"
#include "includes/selectionsort.h"

int *gen_random(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    /* set the seed */
    srand(1);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    return arr;
}

void printSplit(int *arr, int size, int threshold)
{
    int low[10] = {0}, high[10] = {0};
    int h = 0, l = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) > threshold)
        {
            high[h] = *(arr + i);
            h++;
        }
        else
        {
            low[l] = *(arr + i);
            l++;
        }
    }
    printf("higher than threshold: ");
    for (int i = 0; i < h; i++)
        printf("%d ", high[i]);
    printf("\nlower than threshold: ");
    for (int i = 0; i < l; i++)
        printf("%d ", low[i]);
}

int main(void)
{
    int threshold = 0, arr_size = 10;
    int *rand_arr = gen_random(arr_size);
    printArray(rand_arr, arr_size);
    quickSort(rand_arr, 0, arr_size);
    // bubbleSort(rand_arr, arr_size);
    // selectionSort(rand_arr, arr_size);
    printArray(rand_arr, arr_size);

    printf("\nplease enter threshold:");
    scanf("%d", &threshold);
    printf("\n");
    printSplit(rand_arr, arr_size, threshold);
    printf("\nMedian value is %d", *(rand_arr + (arr_size / 2)));
    return 0;
}
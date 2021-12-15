#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "includes/quicksort.h"
#include "includes/bubblesort.h"
#include "includes/selectionsort.h"
#include "includes/insertionsort.h"
#include "includes/heapsort.h"

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
    int *rand_arr2 = NULL;
    memcpy(rand_arr2, rand_arr);
    printArray(rand_arr, arr_size);
    // quickSort(rand_arr, 0, arr_size);
    // bubbleSort(rand_arr, arr_size);
    // selectionSort(rand_arr, arr_size);
    // selectionSortRec(rand_arr, arr_size);
    // insertionSort(rand_arr, arr_size);
    heapSort(rand_arr, arr_size);
    printArray(rand_arr, arr_size);

    int test[10]; // each time expand processing range of predetermined array, call sift up
    for (int i = 0; i < arr_size; i++)
    {
        siftup(rand_arr, i, arr_size);
    }
    printf("\nplease enter threshold:");
    scanf("%d", &threshold);
    printf("\n");
    printSplit(rand_arr, arr_size, threshold);
    printf("\nMedian value is %d", *(rand_arr + (arr_size / 2)));
    return 0;
}
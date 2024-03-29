#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "includes/quicksort.h"
#include "includes/bubblesort.h"
#include "includes/selectionsort.h"
#include "includes/insertionsort.h"
#include "includes/heapsort.h"
#include "includes/mergesort.h"

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
    int threshold = 0, arr_size = 9, seventhSmallest;
    // int *rand_arr = gen_random(arr_size);
    int rand_arr[10] = {53, 12, 98, 63, 18, 32, 80, 46, 72, 21};
    printArray(rand_arr, 0, arr_size + 1);
    quickSort(rand_arr, 0, arr_size);
    // DualPivotQuickSort(rand_arr2, 0, arr_size);
    // bubbleSort(rand_arr, arr_size);
    // selectionSort(rand_arr, arr_size);
    // selectionSortRec(rand_arr, arr_size);
    // insertionSort(rand_arr, arr_size);
    // heapSort(rand_arr, arr_size);
    // heapSortUp(rand_arr2, arr_size);
    // callStackQuickSort(rand_arr, 0, arr_size);
    // mergeSort(rand_arr2, 0, arr_size - 1);
    printArray(rand_arr, 0, arr_size + 1);
    seventhSmallest = kthSmallest(rand_arr, 0, arr_size, 7);
    printf("\nSeventh smallest: %d\n", seventhSmallest);
    // printf("\nplease enter threshold:");
    // scanf("%d", &threshold);
    // printf("\n");
    // printSplit(rand_arr, arr_size, threshold);
    // printf("\nMedian value is %d", *(rand_arr + (arr_size / 2)));

    return 0;
}
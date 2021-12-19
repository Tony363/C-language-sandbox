#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <stdio.h>
#include <stdlib.h>
void printArray(int *rand_arr, int size);
void swap(int *a, int *b);
// int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void DualPivotQuickSort(int *arr, int low, int high);
#endif
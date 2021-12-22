#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <stdio.h>
#include <stdlib.h>
void printArray(int *rand_arr, int low, int high);
void swap(int *a, int *b);
void callStackQuickSort(int *arr, int low, int high);
void quickSort(int arr[], int low, int high);
void DualPivotQuickSort(int *arr, int low, int high);
int kthSmallest(int *arr, int low, int high, int k);
#endif
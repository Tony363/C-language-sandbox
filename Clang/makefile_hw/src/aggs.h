#ifndef AGGS_H
#define AGGS_H
/** @file
 * @brief These are the functions in lib.a.
 */
/**
 * @brief The getAvg class takes in integer array and returns average of the values
 * @param arr is the input
 * @param size is the size of the array
 * @return average of the values in the array.
 */
double getAvg(int *arr, int size);

/**
 * @brief This function calculates the standard deviation of samples from an array
 *
 * @param arr The input value
 * @param size The size of the array
 * @return standard deviation of the samples in the array
 */
double getStd(int *arr, int size);
/**
 @brief The compare function for quicksort
    @param a is the first value
    @param b is the second value
    @return a - b
 */
int cmpfunc(const void *a, const void *b);
#endif
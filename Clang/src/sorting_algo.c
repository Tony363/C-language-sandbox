#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void print_nums(int *nums,int numsSize){
    printf("[");
    for (int i=0;i<numsSize;i++){
        printf("%d,",nums[i]);
    }
    printf("]\n");
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *array = (int *)malloc(sizeof(int)*(*returnSize=numsSize)); 
    if (array == NULL) {
      fprintf(stderr, "malloc failed\n");
      return -1;
    }
    
    for (int i=0;i<numsSize;i++){
        array[i] = nums[i]*nums[i];
        // int temp;
        // //Sort the array in ascending order
        // for (int j=0;j<i;j++){
        //     if (array[j]>array[i]){
        //         temp = array[i];
        //         array[i] = array[j];
        //         array[j] = temp;
        //     }
        // }  
    }
    qsort(array, numsSize, sizeof(int),compare);
    print_nums(array,numsSize);
    return array;
}

int main(void){
    int array[] = {-4,-1,0,3,10};
    int returnSize=0;
    int *sorted = sortedSquares(array,5,&returnSize);
    print_nums(sorted,5);
    return 0;
}
#include <stdio.h>

#include <string.h>
#include <stdlib.h>

int count_digits(int num,int count){
    if (num%10==0 && num/10>0){
        num = num/10;
        count ++;
        return count_digits(num,count);
    }else if (num%10!=0){
        printf("%d",num/10);
        num = num/10;
        count ++;
        return count_digits(num,count);
    }
    printf(":%d\n",count);
    if (count%2==0){
        return 1;
    }
    return 0;
}

int findNumbers(int* nums, int numsSize){
    int count=0,even_num=0;
    for (int i=0;i<numsSize;i++){
        even_num += count_digits(nums[i],count);
    }
    return even_num;
}

int main(void){
    int array[5] = {12,20,15,13,101};
    int array_len = sizeof(array)/sizeof(array[0]);
    printf("Number of Even digit numbers:%d\n",findNumbers(array,array_len));
    return 0;
}
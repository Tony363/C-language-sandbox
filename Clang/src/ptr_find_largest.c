#include <stdio.h>

int *find_largest_address(int a[],int n){
    int largest,index;
    for (int i=0;i<n;i++){
        if (i == 0){
            largest = a[i];
            index = i;
        }
        if (a[i] > largest){
            largest = a[i];
            index = i; 
        }
    }
    int *ptr = a+(sizeof(int)*index);
    return ptr;
}

int find_largest(int a[],int n){
    int largest,index;
    for (int i=0;i<n;i++){
        if (i == 0){
            largest = a[i];
            index = i;
        }
        if (a[i] > largest){
            largest = a[i];
            index = i; 
        }
    }
    return largest;
}


int main(void){
    int arr[] = {0,1,2,3,4,5,6,7};
    printf("address of largest:%p\nlargest number is: %d\n",find_largest_address(arr,8),find_largest(arr,8));
    return 0;
}


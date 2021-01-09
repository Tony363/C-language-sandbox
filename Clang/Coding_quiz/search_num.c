#include <stdio.h>

int search1(int a[], int size, int val) {
    for(int i=0;i<size;i++){
        if(val == a[i]){
            return i;
        }
    }
    return -1;
}

int search(int a[], int size, int val) {
    int i = 0;
    for (i=0; i<size && a[i]!=val; i++);
    return (i>=size)?-1:i;
}

int main(void){
    int a[] = {1, 2, 3};
    printf("%d\n", search(a, sizeof(a)/sizeof(int), 2));
    printf("%d\n", search(a, sizeof(a)/sizeof(int), 4));
    return 0;
}
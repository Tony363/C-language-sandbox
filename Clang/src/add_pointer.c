#include <stdio.h>

int main(void) {
    int n = 10;

    /* your code goes here */
    int *pointer_to_n = &n;
    printf("%d\n",*pointer_to_n);
    *pointer_to_n += 1;
    /* testing code */
    if (pointer_to_n != &n){
        return 1;
    } 
    if (*pointer_to_n != 11){
        return 1;
    } 

    printf("Done!\n");
    return 0;
}
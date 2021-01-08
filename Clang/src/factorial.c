#include <stdio.h>

unsigned int factorial(unsigned int x);

int main() {
    /* testing code */
    printf("0! = %d\n", factorial(0));
    printf("1! = %d\n", factorial(1));
    printf("3! = %d\n", factorial(3));
    printf("5! = %d\n", factorial(5));
}

/* define your function here (don't forget to declare it) */
unsigned int factorial(unsigned int x){
    if (x==0){
        return 1;
    }else if (x==1){
        return x;
    }else if (x>0){
        return x * factorial(x-1);
    }
    return 0;
}
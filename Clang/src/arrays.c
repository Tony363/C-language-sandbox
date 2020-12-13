#include<stdio.h>
// hey hey you see me typing? maybe write your name in the comments here
// if you joined.
// this is the my solution for assignment # 2 due today

int read_into_array(double *array, int n_elem) {
    double input;
    int size=0;
    while (scanf("%lf", &input) == 1){   
        if (size == n_elem){
            return size;
        }
        array[size] = input;
        size++;
    }
    return size;
}
 
int main(void){
    double a[7];
    int n;
    n = read_into_array(a, 7);
    for (;--n>=0;) { printf("%lf\n", a[n]); }
    return 0;
}

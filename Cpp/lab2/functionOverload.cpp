#include <iostream>
#include <cmath>
// #include <stdio.h>
// #include <math.h>
using namespace std;

void small_to_large(float *n1,float *n2,float *n3);
void swap(float *a,float *b);
void swap(float &a,float &b);
void sort3R(float &x, float &y, float z);
void sort3P(float *x, float *y, float *z);
void math_sort(float *n1,float *n2,float *n3);
void math_sort(float n1,float n2,float n3);

int main (void){
    float a=3,b=2,c=1;
    printf("%f:%f:%f\n",a,b,c);
    // sort3R(a,b,c);
    math_sort(a,b,c);
    printf("%f:%f:%f\n",a,b,c);

    // float *a_ptr=&a,*b_ptr=&b,*c_ptr=&c;
    // a_ptr = (float*)malloc(sizeof(float));
    // b_ptr = (float*)malloc(sizeof(float));
    // c_ptr = (float*)malloc(sizeof(float));
    // *a_ptr=1;*b_ptr=2;*c_ptr=3;
    // sort3P(a_ptr,b_ptr, c_ptr);
    // small_to_large(c_ptr,b_ptr,a_ptr);
    math_sort(&a,&b,&c);
    printf("%f:%f:%f\n",a,b,c);
    // free(a_ptr);free(b_ptr);free(c_ptr);

    return 0;
}

void small_to_large(float *n1,float *n2,float *n3){
    float arr[] = {*n1,*n2,*n3};
    float biggest = arr[0];
    float smallest = arr[0];
    for(int i = 1; i < 3; i++) {
        if( smallest > arr[i] ) 
            smallest = arr[i];
        if( biggest < arr[i] ) 
            biggest = arr[i];
    }
    *n1 = smallest;
    *n3 = biggest;
    *n2 = (arr[0] != smallest && arr[0] != biggest)?(arr[1] != smallest && arr[1] != biggest)?:arr[1]:arr[0];
}

void swap(float *a,float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
void swap(float &a,float &b){
    float temp = a;
    a = b;
    b = temp;
}

// Function prototype for call-by-address using reference
void sort3R(float &x, float &y, float z){
    if (x < y)
        swap(x, y);

    if (x < z)
        swap(x, z);

    if (y < z)
        swap(y, z);
}

// Function prototype for call-by-address using pointers
void sort3P(float *x, float *y, float *z){
    if (*x < *y)
        swap(x, y);

    if (*x < *z)
        swap(x, z);

    if (*y < *z)
        swap(y, z);
}

void math_sort(float n1,float n2,float n3){
    float tmp=n1;
    float arr[] = {n1,n2,n3};
    n1 = fmin(n1,fmin(n2,n3));
    float tmp1 = n3;
    n3 = fmax(tmp,fmax(n2,n3));
    int count = 0;
    while(count < 3){
        if(arr[count] != n1 && arr[count] != n3){
            n2 = arr[count];
        }
        count++;
    }
}

void math_sort(float *n1,float *n2,float *n3){
    float tmp=*n1;
    float arr[] = {*n1,*n2,*n3};
    *n1 = fmin(*n1,fmin(*n2,*n3));
    float tmp1 = *n3;
    *n3 = fmax(tmp,fmax(*n2,*n3));
    int count = 0;
    while(count < 3){
        if(arr[count] != *n1 && arr[count] != *n3){
            *n2 = arr[count];
        }
        count++;
    }
}
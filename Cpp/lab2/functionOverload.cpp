#include <iostream>
#include <cmath>
using namespace std;

void swap(float *a,float *b);
void swap(float &a,float &b);
template<typename T>
void s(T &a, T &b);
void sort3R(float &x, float &y, float &z);
void sort3P(float *x, float *y, float *z);
void math_sort(float *n1,float *n2,float *n3);
void math_sort(float n1,float n2,float n3);

int main (void){
    float a=3,b=2,c=1;
    printf("%f:%f:%f\n",a,b,c);
    sort3R(a,b,c);
    // math_sort(a,b,c);
    printf("%f:%f:%f\n",a,b,c);
    sort3P(&a,&b, &c);
    // small_to_large(c_ptr,b_ptr,a_ptr);
    // math_sort(&a,&b,&c);
    printf("%f:%f:%f\n",a,b,c);
    // free(a_ptr);free(b_ptr);free(c_ptr);

    return 0;
}
template<typename T>
void s(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
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
void sort3R(float &x, float &y, float &z){
    if (x > y)
        s(x, y);

    if (x > z)
        s(x, z);

    if (y > z)
        s(y, z);
}

// Function prototype for call-by-address using pointers
void sort3P(float *x, float *y, float *z){
    if (*x > *y)
        s(*x, *y);

    if (*x > *z)
        s(*x, *z);

    if (*y > *z)
        s(*y, *z);
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

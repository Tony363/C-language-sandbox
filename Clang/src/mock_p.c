
#include <stdio.h>
#include <math.h>

struct Tuple {
    int *a, *b;
};

struct Tuple swap(int *first,int *second){
    printf("before | %p:%p | %d:%d\n",first,second,*first,*second);
    int *tmp;
    tmp = first;
    first = second;
    second = tmp;
    printf("after | %p:%p | %d:%d\n",first,second,*first,*second);
    struct Tuple r = {first,second};
    return r;
}

void s(int a, int b){
    int tmp;
    tmp = a;
    a = b; 
    b = tmp;
}
void small_to_large(int *n1,int *n2,int *n3){
    int arr[] = {*n1,*n2,*n3};
    int biggest = arr[0];
    int smallest = arr[0];
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
void math_sort(int *n1,int *n2,int *n3){
    int tmp=*n1;
    int arr[] = {*n1,*n2,*n3};
    *n1 = fmin(*n1,fmin(*n2,*n3));
    int tmp1 = *n3;
    *n3 = fmax(tmp,fmax(*n2,*n3));
    int count = 0;
    while(count < 3){
        if(arr[count] != *n1 && arr[count] != *n3){
            *n2 = arr[count];
        }
        count++;
    }
    
}

int main(void){
    int a=3,b=2,c=1;
    // s(a,b);
    // printf("%d:%d\n",a,b);
    // int *aptr=&a,*bptr=&b;
    // struct Tuple r = swap(aptr,bptr);
    // printf("%d:%d\n",a,b);
    // printf("%d:%d\n",*aptr,*bptr);
    // printf("%d:%d\n",*r.a,*r.b);
    // printf("%d\n%d\n%d\n",a,b,c);
    // small_to_large(&a,&b,&c);
    printf("%d\n%d\n%d\n",a,b,c);
    math_sort(&a,&b,&c);
    printf("%d\n%d\n%d\n",a,b,c);
    return 0;
}


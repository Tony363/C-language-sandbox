#include <stdio.h>

void f(int **ptr,int **ptr1){
    // printf("%p %p\n",*ptr,*ptr1);
    int *temp;
    temp = *ptr;
    *ptr = *ptr1;
    *ptr1 = temp;
    // printf("%p %p %d\n",*ptr,*ptr1, *temp);
}
int main()
{
    int a=1,b=2;
    int *ptr=&a,*ptr1=&b;
    printf("%p %p\n",ptr,ptr1);
    f(&ptr,&ptr1);
    printf("%p %p\n",ptr,ptr1);
    return 0;
}

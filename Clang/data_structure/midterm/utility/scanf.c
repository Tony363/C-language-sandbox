/* Sample C program to demonstrate use of *s */
#include <stdio.h>
int main()
{
    int a;
    scanf("%*s %d", &a);
    printf("Input value read : a=%d", a);
    return 0;
}

// Input: "blablabla 25"
// Output: Value read : 25
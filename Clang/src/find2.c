#include <stdio.h>

int HM2(int n) 
{ 
    int count = 0; 
    while (n > 0) 
    { 
        if (n % 10 == 2) 
            count++; 
        n = n / 10; 
    } 
    return count; 
} 

int HM2from1(int n)
{
    int count = 0 ;
    for (int i = 2; i <= n; i++)
        count += HM2(i);
    return count;
}

int main(int argc, char **argv){
	int n;
	printf("Please input a number for range: ");
	scanf("%d", &n);
	printf("The result is %d\n",HM2from1(n));
	return 0;
}

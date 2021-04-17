#include <stdio.h> 
int func();

int main()  
{  
   printf("%d",func());  
   printf("\n%d",func());  
   printf("\n%d",func());  
  
    return 0;  
}  
int func()  
{  
    static int count;  
    count++;  
    return count;  
}
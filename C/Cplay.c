#include<stdio.h>

int main(int *count)
{
     if (count == NULL)
     {
         return -1;
     }
     printf("hello");
     (*count)++;
     if (*count == 5)
     {
         return 0;
     }
     main(count);
}

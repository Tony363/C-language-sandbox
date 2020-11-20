#include<stdio.h>
#include<stdlib.h>

int helloworld(int result,int count);

int main(int argc,char *argv[])
{  
    char *input = argv[1]; 
    int result = atoi(input);
    int count = 0;
    helloworld(result,count);
    return 0;
}

int helloworld(int result,int count)
{
    if (count != result)
    {
	for(int i=0;i<result-count;i++)
	{
	    printf(" ");
	}
	for(int j=0;j<count*2;j++)
	{
	    printf("#");
	}
	printf("\n");
        count ++;
        return helloworld(result,count);
    }
    else
    {
        printf("exiting program\n");
        return 0;
    }
}

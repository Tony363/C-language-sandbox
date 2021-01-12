#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	int arr_num,num,count=0;
	printf("Enter Array size:\n");  
	scanf("%d",&arr_num);
	int *arr = (int*)malloc(arr_num * sizeof(int));
	for(int i=0;i<arr_num;i++){
		printf("Enter Array element value:\n");
		scanf("%d",&num);
		*(arr+i * sizeof(int)) = num;
		count = count + *(arr+i*sizeof(int));
		}
		printf("%d\n",count);
		return 0;
}

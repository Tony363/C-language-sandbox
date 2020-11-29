#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, *arr, i;
	scanf("%d", &num);
	//int x[num];
	arr = (int*) malloc(num * sizeof(int));
	//arr=x;
	for(i = 0; i < num; i++) {
		scanf("%d", arr + i);
		}
	int temp,end=num-1,start = 0;
	while(start<end){
		temp = *(arr+start);
		*(arr+start) = *(arr+end);
		*(arr+end) = temp;
		start++;
		end--;										    }

					    /* Write the logic to reverse the array. */
	for(i = 0; i < num; i++){
		printf("%d\n", *(arr + i));
	}
	return 0;
}


#include<stdio.h>

int main(void){
    int input,max,count;
    while(scanf("%d",&input)==1){
        if(input==0){
            break;
        }
        if(count==0){
            max = input;
        }
        if (input>max){
            max = input;
        }
        
        count++;
    }
    printf("%d\n",max);
    return 0;
}

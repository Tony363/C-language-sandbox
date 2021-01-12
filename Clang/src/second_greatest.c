#include<stdio.h>
#include<limits.h>

//int second_greatest();
//int second_minamum();

//int main (int argc, char **argv) {
//    //second_greatest();
//    second_minamum();
//    return 0;
//}

int second_greatest(){
    int number,greatest,second_greatest;
    scanf("%d",&number);
    greatest = number;
    second_greatest = number;
    while(number>=0){
        scanf("%d",&number);
        if (number>greatest){
            second_greatest = greatest;
            greatest = number;
        }
        if (number>second_greatest && number<greatest){
            second_greatest = number;
        }
    }
    printf("%d\n",second_greatest);
    return second_greatest;
}

int second_minamum(){
    int number,minamum,second_minamum;
    scanf("%d",&number);
    minamum = number;
    second_minamum = INT_MAX;
    while(number>=0){
        scanf("%d",&number);
        if(number<minamum){
            second_minamum = minamum;
            minamum = number;
        }
        if(number>minamum && number< second_minamum){
            second_minamum = number;
        } 
        printf("minamum %d: second minamum%d\n",minamum,second_minamum); 
    }
    printf("%d\n",second_minamum);
    return second_minamum;
}



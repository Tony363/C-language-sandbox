#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void){
    char input1[10]={0},input2[10]={0},*comma = ",";
    scanf("%s %s",input1,input2);
    if (strchr(input1,',')!=NULL){
        for (int i=0;i<strlen(input1);i++){
            input1[i] = toupper(input1[i]);
        }
        printf("%s %s\n",input1,input2);
    }else{
        for (int i=0;i<strlen(input1);i++){
            input2[i] = toupper(input2[i]);
        }
        printf("%s%s %s\n",input2,comma,input1);
    }
    return 0;
}

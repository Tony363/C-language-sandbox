#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char input[20],first[20],second[20];
    scanf("%s",input);
    sscanf(input,"%s %s",first,second);
    for (int i=0;i<strlen(first);i++){
        first[i] = tolower(first[i]);
    }
    for (int i=0;i<strlen(first);i++){
        second[i] = tolower(second[i]);
    }
    if (strcmp(first,second)!=0){
        printf("True\n");
    }else {
        printf("False\n");
    }
    return 0;
}
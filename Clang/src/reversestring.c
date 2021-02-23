#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *reverseString(char *original,char *initial, int index){
    if (original[index-1] == '\0')
        return initial;
    initial[index] = original[strlen(original)-index];
    index++;
    return reverseString(original,initial,index);
}

void printstring(char *str,int char_len){
    for (int i=0;i<char_len;i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
int main(void){
    int character_count = 1,char_len;
    scanf("%d",&char_len);
    char *original = (char*)malloc(char_len*sizeof(char));
    scanf("%s",original);
    char *Reversed = (char*)malloc(char_len*sizeof(char));
    char *Reversed_string = reverseString(original,Reversed,character_count);
    printstring(Reversed_string,char_len+1);
    return 0;
}

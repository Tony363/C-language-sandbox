#include <stdio.h>
#include <string.h>
#include <ctype.h>

void parse_s(char *s){
    for (int i=0,firstc=0;i<strlen(s);i++){
        if (isalpha(s[i])!=0){
            s[i] = (firstc==0)?toupper(s[i]):tolower(s[i]);
            firstc++;
        }else{
            firstc=0;
        }
    }
}

int main(void){
    char str[] = "hello, world.";
    parse_s(str);
    printf("%s\n", str);
}
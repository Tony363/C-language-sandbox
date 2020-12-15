#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cvt_str(char *s){
    for (int i=0,firstc=0;i<strlen(s);i++,firstc=(isalpha(s[i])!=0)?1+firstc:-1){   
        s[i] = (isalpha(s[i])!=0&&firstc==0)?toupper(s[i]):tolower(s[i]);
    }
}

int main(void){
    char str[] = "hello, world.";
    parse_s(str);
    printf("%s\n", str);
}
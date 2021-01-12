#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *join_two(const char *s1,const char *s2) {
    char *str = (char *)malloc((strlen(s1)+strlen(s2))*sizeof(char));   
    strcpy(str,s1);
    strcat(str,s2);
    return str;
}
int main(void){
    const char *s1 = "hello";
    const char *s2 = "world";
    char *s3 = join_two(s1, s2);
    printf("%s, %s, %s\n", s1, s2, s3);
    free(s3);
    return 0;
}
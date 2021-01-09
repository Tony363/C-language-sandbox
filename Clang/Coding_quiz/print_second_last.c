#include <stdio.h>

int main(int argc, char **argv) {
    char s1[100]={0}, s2[100]={0}, s3[100]={0}, *prev2, *prev1, *curr;
    double v;
    
    prev2 = s1; prev1 = s2; curr = s3;
    do {
        char *tmp;
        tmp = prev2; prev2 = prev1; prev1 = curr; curr = tmp;
        scanf("%s", curr);
        sscanf(curr, "%lf", &v);
    } while (v!=0);
    printf("%s", prev2);
    return 0;
}
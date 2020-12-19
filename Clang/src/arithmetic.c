# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int main (void){
    char symbol;
    char mult='*',add='+',sub='-',div='/';
    int a,b;
    scanf("%d %c %d", &a, &symbol, &b);
    printf("%d %c %d\n",a,symbol,b);
    if (symbol == '*'){
        printf("%d\n",a+b);
    }else if (symbol == '-'){
        printf("%d\n",a-b);
    }else if (symbol == '/'){
        printf("%d\n",a/b);
    }else if (symbol == '*'){
        printf("%d\n",a*b);
    }else{
        printf("wrong operator\n");
    }
    return 0;
}
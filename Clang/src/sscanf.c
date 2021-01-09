#include <stdio.h>
#include <string.h>

void print_phone_num(char *number){
    char string_array[4][10] = {0};
    char string[100];
    char *pch;
    pch = strtok(number,"().- ");
    int count = 0;
    while (pch != NULL){
        memcpy(string_array[count],pch,strlen(pch));
        pch = strtok(NULL,"().- ");
        count ++;
    }
    printf("(%s) %s-%s\n",string_array[0],string_array[1],string_array[2]);
}

void print_no_delim(char *number){
    char *region,*first,*second;
    for (int i=0,pairs=0;i<strlen(number);i++,pairs=(i%3==0)?pairs+1:pairs){
        if (pairs==0){
            
        } else if (pairs==1){

        }else {

        }
    }
}
int main (void){
    char *contents = "content=0&website=Google";
    char arg[100] = {0};
    char value[100] = {0};
    sscanf(contents, "%[^&]&%s", arg, value);
    printf("%s\n%s\n", arg, value);
    char phone_numbers[4][15] = {
        "404.817.6900",
        "(215) 686-1776",
        "312-746-6000",
        "877 275 5273"
        };
    int n_phone = (sizeof(phone_numbers)/sizeof(phone_numbers[0]));
    for (int i=0;i<n_phone;i++){
        // printf("%d:%s\n",i,phone_numbers[i]);
        print_phone_num(phone_numbers[i]);
    }
    char phone_number5[] = "6173434200";
    // print_phone_num(phone_number1);
    return 0;
}

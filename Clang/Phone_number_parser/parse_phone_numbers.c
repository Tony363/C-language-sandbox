#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    char region[4]={0},first[4]={0},second[5]={0};
    int index=0;
    for (int i=0,pairs=0;i<strlen(number);i++,pairs=(i%3==0&&i<9)?pairs+1:pairs){
        if (index >= 3&&i<9){
            index = 0;
        }
        if (pairs==0){
            region[index] = number[i];
        }else if (pairs==1){
            first[index] = number[i];   
        }else {
            second[index] = number[i];      
        }
        index++;
    }
    printf("(%s) %s-%s\n",region,first,second);
}

int main (int argc,char** argv){
    char *contents = "content=0&website=Google";
    char arg[100] = {0};
    char value[100] = {0};
    sscanf(contents, "%[^&]&%s", arg, value);
    printf("%s\n%s\n\n", arg, value);
    // reading from file with path from command line
    if (argc < 2){
        return -1;
    }
    FILE *file = fopen(argv[1],"r");char line[100];
    if (file == NULL){
        exit(EXIT_FAILURE);
    }
    char period='.',hyphon='-',paren1='(',paren2=')',space=' ';
    while (fgets(line,100,file)!=0){
        if (strchr(line,period)==NULL&&
            strchr(line,hyphon)==NULL&&
            strchr(line,paren1)==NULL&&
            strchr(line,paren2)==NULL&&
            strchr(line,space)==NULL){
            line[strlen(line)-1] = 0;
            print_no_delim(line);
        }else{
            line[strlen(line)-1] = 0;
            print_phone_num(line);
        }
    }
    // using array of c strings
    printf("\nreading from array of c stings\n\n");
    char phone_numbers[5][15] = {
        "404.817.6900",
        "(215) 686-1776",
        "312-746-6000",
        "877 275 5273",
        "6173434200"
        };
    int n_phone = (sizeof(phone_numbers)/sizeof(phone_numbers[0]));
    for (int i=0;i<n_phone;i++){   
        if (strchr(phone_numbers[i],period)==NULL&&
            strchr(phone_numbers[i],hyphon)==NULL&&
            strchr(phone_numbers[i],paren1)==NULL&&
            strchr(phone_numbers[i],paren2)==NULL&&
            strchr(phone_numbers[i],space)==NULL){
            print_no_delim(phone_numbers[i]);
        }else{
            print_phone_num(phone_numbers[i]);
        }
    }
    return 0;
}

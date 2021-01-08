#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct number{
    char first[3+1];
    char second[3+1];
    char third[4+1];
} Phone_Number;

void print_phone_number(Phone_Number phone_number){
    for (int i=0;i<3;i++){
        if (i == 0){
            printf("(%c",phone_number.first[i]);
           
        }else if (i == 2){
            printf("%c) ",phone_number.first[i]);
        }else{
            printf("%c",phone_number.first[i]);
        }
        
    }
  
    for (int i=0;i<3;i++){
        if (i == 2){
            printf("%c-",phone_number.second[i]);
        } else{
            printf("%c",phone_number.second[i]);
        }
    }

    for (int i=0;i<4;i++){
        if (i == 3){
            printf("%c\n",phone_number.third[i]);
        } else{
            printf("%c",phone_number.third[i]);
        }
    }
}

int main (void){
    FILE *fp;
    char line[100];
    int number_len = 3;
    fp = fopen("/home/tony/Desktop/My_repos/Clang_sandbox/Clang/Texts/phone_numbers.txt","r");
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }
    while (fgets(line,100,fp)!=0){

        int char_count=0,number_count=0;
        Phone_Number phone_number;
        for (int i=0;i<strlen(line);i++){
            if (char_count == 3 && number_count != 2){
                char_count = 0;
                number_count ++;
            }else if (number_count == 2 && char_count > 3){
                char_count = 0;
            }
            if (isdigit(line[i])!=0){
                if (number_count == 0){
                    phone_number.first[char_count] = line[i];  
                } else if (number_count == 1){
                   
                    phone_number.second[char_count] = line[i];  
                } else{   
                    phone_number.third[char_count] = line[i];
                }
                char_count++;
             
            }   
        }
        print_phone_number(phone_number);
    }
    return 0;
}
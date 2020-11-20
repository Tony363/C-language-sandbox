#include <stdio.h>
#include <string.h>

void reverseString(char* str);

int main(void){
    char *Tony = "Tony";
    
    //char Tony[10] = "Tony";
    //reverseString(Tony);
    char *myname = Tony;
    char **myalmightyname = &myname;
    char *begin_ptr,*end_ptr,ch;
    begin_ptr = *myalmightyname;
    end_ptr = *myalmightyname;
    int l = strlen(*myalmightyname);
    printf("%d\n",l);
    for (int i=0;i<l-1;i++){
        end_ptr++;
    }
    for (int i=0;i<l/2;i++){
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;
        begin_ptr++;
        end_ptr--;
    }
    printf("%s\n",*myalmightyname);
    return 0;
}

void reverseString(char* str) 
{ 
    int l, i; 
    char *begin_ptr, *end_ptr, ch; 
  
    // Get the length of the string 
    l = strlen(str); 
  
    // Set the begin_ptr and end_ptr 
    // initially to start of string 
    begin_ptr = str; 
    end_ptr = str; 
  
    // Move the end_ptr to the last character 
    for (i = 0; i < l - 1; i++) 
        end_ptr++; 
  
    // Swap the char from start and end 
    // index using begin_ptr and end_ptr 
    for (i = 0; i < l / 2; i++) { 
  
        // swap character 
        ch = *end_ptr; 
        *end_ptr = *begin_ptr; 
        *begin_ptr = ch; 
  
        // update pointers positions 
        begin_ptr++; 
        end_ptr--; 
    } 
}

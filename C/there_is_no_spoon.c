#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    
    int width, height;
    char line[32];
    // the number of cells on the X axis
    scanf("%d", &width);
    // the number of cells on the Y axis
    scanf("%d", &height); 
    fgetc(stdin);
    //printf("%d,%d\n",width,height);
    int nodes[height];
    for (int i = 0; i < height; i++) {
        // width characters, each either 0 or .
        fgets(line, 32, stdin);
        nodes[i] = atoi(line);
        printf("%d",nodes[i]);
    }
    printf("\n");
    int len = sizeof(nodes)/sizeof(nodes[0]);   
    printf("lenght: %d\n",len); 
    for (int j=0;j<len;j++){
        printf("%d ",nodes[j]);
    }
    printf("\n");
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    //printf("0 0 1 0 0 1\n");

    return 0;
}




#include <stdio.h>

void print_array(int *array,int arraySize){
    printf("[");
    for(int i=0;i<arraySize;i++){
        printf("%d,",array[i]);
    }
    printf("]\n");
}

void duplicateZeros(int *arr, int arrSize){
    int i=0,temp;
    print_array(arr,arrSize);
    while (i<arrSize){
        printf("%d\n",arr[i]);
        if (arr[i] == 0){
            for (int j=arrSize+1;j>=i;j--){
                // printf("prev %d ",arr[j-1]);
                arr[j-1] = arr[j-2];
                // printf("current %d\n",arr[j-1]);
            }
            // previous i is current i
            arr[i] = 0; 
            print_array(arr,arrSize);
            i+=1;
        }
        i++;
    }
    // print_array(arr,arrSize);
}

// typedef struct _queue{
//     int v;
//     struct _queue *next;
// }q, q_p;

// void duplicateZeros(int* arr, int arrSize){
//     int i, move=0, last_i;
    
//     for(i=0;i<arrSize;i++){
        
//         if(arr[i]==0 && i<arrSize-1){
//             int tmp = arr[i+1];
//             arr[++i]=0;
//             arr[++i] = tmp;
//             last_i=i;
//             move++;
//         }
//     }
//     for(i=last_i;i<arrSize-1;i++){
//         int tmp = arr[i];
//         arr[++i] = tmp;
//     }
//     print_array(arr,arrSize);
// }

int main(void){
    int array[] = {1,0,2,3,0,4,5,0};
    int arraySize = sizeof(array)/sizeof(array[0]);
    duplicateZeros(array,arraySize);
    return 0;
}
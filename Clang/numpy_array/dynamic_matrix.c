#include <stdio.h>
#include <stdlib.h>

// structure wrapper to 2d or 1d

typedef struct IntMat{
    char type;
    int rows,cols;
    void *data;
} IntMat;

void *createMat(int rows,int cols){
    IntMat *m = (IntMat *)malloc(sizeof(IntMat));
    m->type = '0';
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(sizeof(int)*rows*cols);
    return m;
}

void transMat(IntMat *m){
    // IntMat *t = (IntMat *)malloc(sizeof(IntMat));
    int temp;
    temp = (m)->rows;
    (m)->rows = (m)->cols;
    (m)->cols = temp;
    // m->data = m;
    (m)->type = '1';
    // return m;
}

void set(IntMat *m,int i, int j,int value){
    if (m->type == '0')
        *(((int *)m->data)+(i*m->cols)+j) = value;
    else if (m->type == '1'){
        set(m,j,i,value);
    }
}

int get(IntMat *m,int i,int j){
    if (m->type == '0'){
        //return ((int)(m->data))+(i*(m->cols))+j;
        return *(((int *)m->data)+(i*(m->cols))+j);
    }else if(m->type == '1'){
        return *(((int *)m->data)+(j*(m->cols+1))+i);
    }
}

int **matrix(int r,int c){
    int **arr = (int **)malloc(r * sizeof(int *)); 
    for (int i=0; i<r; i++) 
        arr[i] = (int *)malloc(c * sizeof(int)); 
    return arr;
}

void printMatrix(IntMat *matrix){
    for (int i=0;i<matrix->rows;i++){
        printf("[");
        for (int j=0;j<matrix->cols;j++){
            printf("%d ",get(matrix,i,j));
        }
        printf("]\n");
    }
    printf("\n");
}

int main(void){
    int row, col,input;
    printf("Enter rows:\n");scanf("%d",&row);
    printf("Enter cols:\n");scanf("%d",&col);
    IntMat *matrix = createMat(row,col);
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            printf("Enter value for matrix[%d][%d]:\n",i,j);
            scanf("%d",&input);
            set(matrix,i,j,input);
        }
    }
    printMatrix(matrix);
    transMat(matrix);
    printf("%d\n",get(matrix,0,1));
    printMatrix(matrix);
    return 0;
}
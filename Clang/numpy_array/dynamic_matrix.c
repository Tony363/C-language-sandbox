#include <stdio.h>
#include <stdlib.h>

// structure wrapper to 2d or 1d

typedef struct IntMat{
    char type,result;
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
    int temp;
    temp = (m)->rows;
    (m)->rows = (m)->cols;
    (m)->cols = temp;
    (m)->type = '1';
}

void set(IntMat *m,int i, int j,int value){
    if (m->type == '0'){
        *(((int *)m->data)+(i*m->cols)+j) = value;
        m->result = 'S';
    }
    else if (m->type == '1'){
        set(m,j,i,value);
        m->result = 'S';
    }
}

int get(IntMat *m,int i,int j){
    if (m->cols == m->rows){
        if (m->type == '0'){
            return *(((int *)m->data)+(i*(m->cols))+j);
        }else if(m->type == '1'){
            return *(((int *)m->data)+(j*(m->cols))+i);
        }    
    }else{
        if (m->type == '0'){
            //return ((int)(m->data))+(i*(m->cols))+j;
            return *(((int *)m->data)+(i*(m->cols))+j);
        }else if(m->type == '1'){
            return *(((int *)m->data)+(j*(m->cols+1))+i);
        }
    }
}

void printMatrix(IntMat *matrix){
    if (matrix->result == 'S'){
        for (int i=0;i<matrix->rows;i++){
            printf("[");
            for (int j=0;j<matrix->cols;j++){
                printf("%d ",get(matrix,i,j));
            }
            printf("]\n");
        }
        printf("\n");
    }else{
        printf("matrix not populated\n");
    }

}

IntMat *dotProduct(IntMat *matrix,IntMat *vector){
    IntMat *m = createMat(matrix->rows,matrix->cols);
    if (matrix->cols == vector->rows){
        for (int i=0;i<m->rows;i++){
            for (int j=0;j<m->cols;j++){
                // printf("%d\n",(*(((int *)matrix->data)+(i*(matrix->cols))+j))*(*(((int *)vector->data)+(i*(vector->cols))+j)));
                set(m,i,j,(*(((int *)matrix->data)+(i*(matrix->cols))+j))*(*(((int *)vector->data)+(i*(vector->cols))+j)));
            }
        }
        m->result = 'S';
        return m;
    }else {
        printf("wrong dot product dimensions\n");
        m->result = 'F';
        return m;
    }
}

int main(void){
    int row, col,input;
    printf("Enter rows:\n");scanf("%d",&row);
    printf("Enter cols:\n");scanf("%d",&col);
    IntMat *matrix = createMat(row,col);
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            printf("Enter value for matrix[%d][%d]:\n",i,j);scanf("%d",&input);
            set(matrix,i,j,input);
        }
    }
    matrix->result = 'S';
    IntMat *matrixCopy = matrix;
    printMatrix(matrix);
    transMat(matrix);
    printMatrix(matrix);
    IntMat *dotprodMatrix = dotProduct(matrixCopy,matrix);
    printMatrix(dotprodMatrix);
    return 0;
}
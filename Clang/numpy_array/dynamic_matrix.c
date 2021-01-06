#include <stdio.h>
#include <stdlib.h>

// structure wrapper to 2d or 1d

typedef struct IntMat{
    char type,result;
    int rows,cols;
    void *data;
} IntMat;

typedef struct MatMulVal{
    int value;
} MatMulVal;

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

IntMat *copy(IntMat *mat){
    IntMat *m = createMat(mat->rows,mat->cols);
    for (int i=0;i<mat->rows;i++){
        for (int j=0;j<mat->cols;j++){
            //printf("Enter value for matrix[%d][%d]:\n",i,j);scanf("%d",&input);
            set(m,i,j,*(((int *)mat->data)+(i*(mat->cols))+j));
        }
    }
    return m;
}

IntMat *dotProduct(IntMat *matrix,IntMat *vector){
    IntMat *m = createMat(matrix->rows,vector->cols);
    if (matrix->rows == vector->cols || matrix->cols == vector->rows){
        for (int i=0,j=0;i<matrix->rows,j<vector->cols;i++,j++){
            // i iterates matrix rows
            // j interates vectors cols
            int value=0,m_val,v_val;
            for (int m_iter=0,v_iter=0;m_iter<matrix->cols,v_iter<vector->rows;m_iter++,v_iter++){
                // m_iter is number columns for each row in input matrix
                // v_iter is number rows in column in vector matrix
                m_val = (*(((int *)matrix->data)+(i*(matrix->cols))+(m_iter)));
                v_val = (*(((int *)vector->data)+(j*(vector->rows))+v_iter));
                value += (m_val * v_val);
                // Debug outputs
                // printf("m:v = %d:%d\n", m_val, v_val);
                // printf("value: %d\n",m_val * v_val);
            }
            set(m,i,j,value);
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
    IntMat *matrixCopy = copy(matrix);
    printMatrix(matrix);
    transMat(matrix);
    printMatrix(matrix);
    IntMat *dotprodMatrix = dotProduct(matrixCopy,matrix);
    printMatrix(dotprodMatrix);
    return 0;
}
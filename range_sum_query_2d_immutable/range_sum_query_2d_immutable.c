#include <stdio.h>
#include <stdlib.h>

// gcc range_sum_query_2d_immutable.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


typedef struct {
    int **matrix;
    int matrixSize;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    /* Pre-computes all matrix subset sums into subMatrices of
     * type NumMatrix. */
    NumMatrix *subMatrices = malloc((matrixSize) * sizeof(NumMatrix));
    subMatrices->matrix = malloc((matrixSize + 1) * sizeof(int*));
    subMatrices->matrixSize = (matrixSize + 1);
    int i, j;
    for(i = 0; i <= matrixSize; i++){
        subMatrices->matrix[i] = calloc((*matrixColSize + 1), sizeof(int));
    }
    for(i = 1; i <= matrixSize; i++){
        for(j = 1; j <= *matrixColSize; j++){
            subMatrices->matrix[i][j] = (
                    subMatrices->matrix[i - 1][j] +
                    subMatrices->matrix[i][j - 1] -
                    subMatrices->matrix[i - 1][j - 1] +
                    matrix[i - 1][j - 1]
                    );

        }
    }
    return subMatrices;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    /* Returns the sum of the elements of matrix inside the rectangle
     * defined by its upper left corner (row1, col1) and lower right corner. */
    return (
            obj->matrix[row2 + 1][col2 + 1] -
            obj->matrix[row2 + 1][col1] -
            obj->matrix[row1][col2 + 1] +
            obj->matrix[row1][col1]
           );
}

void numMatrixFree(NumMatrix* obj) {
    /* Free memory allocated for NumMatrix object. */
    int i;
    for(i = 0; i < obj->matrixSize; i++){
        free(obj->matrix[i]);
    }
    free(obj->matrix);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);

 * numMatrixFree(obj);
*/

// TESTS
int main(void){
    int returnVal = 0;
    int result;
    int mS = 5;
    int mCS = 5;
    int a[5] = {3, 0, 1, 4, 2};
    int b[5] = {5, 6, 3, 2, 1};
    int c[5] = {1, 2, 0, 1, 5};
    int d[5] = {4, 1, 0, 1, 7};
    int e[5] = {1, 0, 3, 0, 5};
    int **matrix = malloc(mS * sizeof(int*));
    matrix[0] = a, matrix[1] = b, matrix[2] = c, matrix[3] = d, matrix[4] = e;
    NumMatrix *testMatrix = numMatrixCreate(matrix, mS, &mCS);

    // PRINTS FOR DEV DEBUGGING //
    /*
    int i, j;
    for(i = 0; i <= mS; i++){
        for(j = 0; j <= mCS; j++){
            printf("%d ", testMatrix->matrix[i][j]);
        }
    }
    printf("\n %d\n", numMatrixSumRegion(testMatrix, 2, 1, 4, 3));
    */

    // assert [2, 1, 4, 3] == 8
    result = numMatrixSumRegion(testMatrix, 2, 1, 4, 3);
    if(result != 8){returnVal = 1;}
    printf("\n%d", result);

    //assert [1, 1, 2, 2] == 11
    result = numMatrixSumRegion(testMatrix, 1, 1, 2, 2);
    if(result != 11){returnVal = 1;}
    printf("\n%d", result);

    //assert [1, 2, 2, 4] == 12
    result = numMatrixSumRegion(testMatrix, 1, 2, 2, 4);
    if(result != 12){returnVal = 1;}
    printf("\n%d", result);

    printf("\n");
    numMatrixFree(testMatrix);
    free(matrix);
    return returnVal;
}

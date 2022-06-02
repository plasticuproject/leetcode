#include <stdio.h>
#include <stdlib.h>

// gcc transpose_matrix.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 1000


int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    /* Given a 2D integer array matrix,
     * returns the transpose of matrix. */
    *returnSize = *matrixColSize;
    *returnColumnSizes = malloc(*matrixColSize * sizeof(int));
    int** result = malloc(*matrixColSize * sizeof(int*));

    int i, j;
    for(i = 0; i < *matrixColSize; i++){
        result[i] = malloc(matrixSize * sizeof(int));
        (*returnColumnSizes)[i] = matrixSize;
        for(j = 0; j < matrixSize; j++){
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}


// TESTS
int main(void){
    int returnVal = 0;
    int mS, mCS;
    int rS = 0;
    int *rCS = 0;
    int **result;
    int **m = malloc((MAX * MAX) * sizeof(int));
    int **test = malloc((MAX * MAX) * sizeof(int));
    int i, j;
    for(i = 0; i < MAX; i++){
        m[i] = malloc(MAX * sizeof(int));
        test[i] = malloc(MAX * sizeof(int));
    }

    // assert [[1, 2, 3], [4, 5, 6], [7, 8, 9]] == [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
    m[0][0] = 1, m[0][1] = 2, m[0][2] = 3;
    m[1][0] = 4, m[1][1] = 5, m[1][2] = 6;
    m[2][0] = 7, m[2][1] = 8, m[2][2] = 9;
    test[0][0] = 1, test[0][1] = 4, test[0][2] = 7;
    test[1][0] = 2, test[1][1] = 5, test[1][2] = 8;
    test[2][0] = 3, test[2][1] = 6, test[2][2] = 9;
    mS = 3, mCS = 3;
    result = transpose(m, mS, &mCS, &rS, &rCS);
    printf("\n[");
    for(i = 0; i < mCS; i++){
        printf("[ ");
        for(j = 0; j < mS; j++){
            printf("%d ", result[i][j]);
            if(result[i][j] != test[i][j]){returnVal = 1;}
        }
        printf("]");
    }
    printf("]");
    for(i = 0; i < mCS; i++){free(result[i]);}
    free(result), free(rCS);

    // assert [[1, 2, 3], [4, 5, 6]] == [[1, 4], [2, 5], [3, 6]]
    m[0][0] = 1, m[0][1] = 2, m[0][2] = 3;
    m[1][0] = 4, m[1][1] = 5, m[1][2] = 6;
    test[0][0] = 1, test[0][1] = 4;
    test[1][0] = 2, test[1][1] = 5;
    test[2][0] = 3, test[2][1] = 6;
    mS = 2, mCS = 3;
    result = transpose(m, mS, &mCS, &rS, &rCS);
    printf("\n[");
    for(i = 0; i < mCS; i++){
        printf("[ ");
        for(j = 0; j < mS; j++){
            printf("%d ", result[i][j]);
            if(result[i][j] != test[i][j]){returnVal = 1;}
        }
        printf("]");
    }
    printf("]");
    for(i = 0; i < mCS; i++){free(result[i]);}
    free(result), free(rCS);

    for(i = 0; i < MAX; i++){
        free(m[i]);
        free(test[i]);
    }
    free(m), free(test);
    printf("\n");
    return returnVal;
}

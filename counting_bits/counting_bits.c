#include <stdio.h>
#include <stdlib.h>

// gcc counting_bits.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 100000

int* countBits(int n, int* returnSize){
    /* Given an integer n, returns an
     * array ans of length n + 1 such that
     * for each i (0 <= i <= n), ans[i] is
     * the number of 1's in the binary
     * representation of i. */
    *returnSize = (n + 1);
    int *ans = calloc(*returnSize, sizeof(int));
    int offset = 1;
    int i;
    for(i = 1; i < *returnSize; i++){
        if(i == (offset * 2)){offset = i;}
        ans[i] = (1 + (ans[i - offset]));
    }
    return ans;
}


// TESTS
int main(void){
    int returnVal = 0;
    int *test = malloc(MAX * sizeof(int));
    int rS = 0;
    int *result;
    int i;

    // assert 2 == [0, 1, 1]
    test[0] = 0, test[1] = 1; test[2] = 1;
    result = countBits(2, &rS);
    printf("\n[ ");
    for(i = 0; i < rS; i++){
        printf("%d ", result[i]);
        if(result[i] != test[i]){returnVal = 1;}
    }
    printf("]");
    free(result);

    // assert 5 == [0, 1, 1, 2, 1, 2]
    test[0] = 0, test[1] = 1, test[2] = 1, test[3] = 2, test[4] = 1, test[5] = 2;
    result = countBits(5, &rS);
    printf("\n[ ");
    for(i = 0; i < rS; i++){
        printf("%d ", result[i]);
        if(result[i] != test[i]){returnVal = 1;}
    }
    printf("]");
    free(result);

    free(test);
    printf("\n");
    return returnVal;
}

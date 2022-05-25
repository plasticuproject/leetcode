#include <stdio.h>
#include <stdlib.h>

// gcc twosum_two.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 30000


int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    /* Given a 1-indexed array of integers numbers that is
     * already sorted in non-decreasing order, finds two numbers
     * such that they add up to the target number. These two
     * numbers are numbers[index1] and numbers[index2]
     * where 1 <= index1 < index2 <= numbers.length.
     * Returns the indices of the two numbers, index1 and index2,
     * added by one as an integer array [index1, index2] of
     * length 2. */
    int minIdx = 0, maxIdx = (numbersSize - 1);
    *returnSize = 2;
    int *ret = malloc(*returnSize * sizeof(int));
    int check = numbers[minIdx] + numbers[maxIdx];
    while(check != target){
        if(check < target){minIdx++;}
        else{maxIdx--;}
        check = numbers[minIdx] + numbers[maxIdx];
    }
    ret[0] = (minIdx + 1), ret[1] = (maxIdx + 1);
    return ret;
}


// TESTS
int main(void){
    int returnVal = 0;
    int rs = 2;
    int *n = malloc(MAX * sizeof(int));
    int t, nS;
    int *result;

    // assert ([2, 7, 11, 15], 9) == [1, 2]
    n[0] = 2, n[1] = 7, n[2] = 11, n[3] = 15;
    t = 9, nS = 4;
    result = twoSum(n, nS, t, &rs);
    printf("\n[%d, %d]", result[0], result[1]);
    if((result[0] != 1) || (result[1] != 2)){returnVal = 1;}
    free(result);

    // assert ([2, 3, 4], 6) == [1, 3]
    n[0] = 2, n[1] = 3, n[2] = 4;
    t = 6, nS = 3;
    result = twoSum(n, nS, t, &rs);
    printf("\n[%d, %d]", result[0], result[1]);
    if((result[0] != 1) || (result[1] != 2)){returnVal = 1;}
    free(result);

    // assert ([-1, 0], -1) == [1, 2]
    n[0] = -1, n[1] = 0;
    t = -1, nS = 2;    result = twoSum(n, nS, t, &rs);
    printf("\n[%d, %d]", result[0], result[1]);
    if((result[0] != 1) || (result[1] != 2)){returnVal = 1;}
    free(result);


    printf("\n");
    free(n);
    return returnVal;
}

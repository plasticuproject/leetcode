#include <stdio.h>

// gcc maximum_subarray.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

int maxSubArray(int* nums, int numsSize){
    /* Given an integer array nums, find the
    * contiguous subarray (containing at least
    * one number) which has the largest sum and
    * return its sum. */
    int previous = nums[0];
    int newSum = 0;
    int i;
    for(i = 0; i < numsSize; i++){
        if(newSum < 0){newSum = 0;}
        newSum += nums[i];
        if(newSum > previous){previous = newSum;}
    }
    return previous;
}


// TESTS
int main(void){
    int returnValue = 0;

    // assert [-2, 1, -3, 4, -1, 2, 1, -5, 4] == 6
    int n[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int s = sizeof(n) / sizeof(int);
    int result = maxSubArray(n, s);
    printf("\n%d", result);
    if(result != 6){returnValue = 1;}

    // assert [5, 4, -1, 7, 8] == 23
    int nTwo[5] = {5, 4, -1, 7, 8};
    int sTwo = sizeof(nTwo) / sizeof(int);
    int resultTwo = maxSubArray(nTwo, sTwo);
    printf("\n%d", resultTwo);
    if(resultTwo != 23){returnValue = 1;}

    // assert [1] == 1
    int nThree[1] = {1};
    int sThree = sizeof(nThree) / sizeof(int);
    int resultThree = maxSubArray(nThree, sThree);
    printf("\n%d", resultThree);
    if(resultThree != 1){returnValue = 1;}

    printf("\n");
    return returnValue;
}

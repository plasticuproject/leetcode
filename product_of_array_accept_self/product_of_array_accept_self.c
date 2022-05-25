#include <stdio.h>
#include <stdlib.h>

// gcc product_of_array_accept_self.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    /* Given an integer array nums, return an array answer
    * such that answer[i] is equal to the product of all the
    * elements of nums except nums[i]. */
    *returnSize = numsSize;
    int *answer = (int*)malloc(sizeof(int) * (*returnSize));
    int left = 1, right = 1;
    int i;
    for(i = 0; i < numsSize; i++){answer[i] = 1;}
    for(i = 0; i < numsSize; i++){
        answer[i] *= left;
        answer[numsSize + ~i] *= right;
        left *= nums[i];
        right *= nums[numsSize + ~i];
    }
    return answer;
}


// TESTS
int main(void){
    int returnValue = 0;
    int i;

    // assert [1, 2, 3, 4] == [24, 12, 8, 6]
    int n[4] = {1, 2, 3, 4};
    int s = sizeof(n) / sizeof(int);
    int test[4] = {24, 12, 8, 6};
    int *result = productExceptSelf(n, s, &s);
    for(i = 0; i < 4; i++){printf("\n%d", result[i]);}
    if(result != test){returnValue = 1;}

    free(result);
    printf("\n");
    return returnValue;
}

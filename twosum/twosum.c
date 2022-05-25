#include <stdio.h>
#include <stdlib.h>

// gcc twosum.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int) * (*returnSize));
    int i, j;
    for(i = 0;i < numsSize; i++){
        for(j = 1;j < numsSize;j++){
            if(i == j){j += 1;}
            if((nums[i] + nums[j]) == target){
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}

int* twoSumHash(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int hashTable[10007] = {0};
    int *result = (int*)malloc(sizeof(int) * (*returnSize));
    int i, diff, key;

    for(i = 0; i < numsSize; i++){
        diff = target - nums[i];
        key = (diff & 0x7fffffff) % 10007;
        if(nums[hashTable[key]] == diff && (hashTable[key] != i)){
            result[0] = hashTable[key];
            result[1] = i;
            break;
        }
        else{
            key = (nums[i] & 0x7fffffff) % 10007;
            hashTable[key] = i;
        }
    }
    return result;
}


// TESTS
int main(void){
    int *result;
    int nS;
    int rS = 0;
    int i;

    // assert [3, 3] == [0, 1]
    int n[2] = {3, 3};
    nS = 2;
    int target = 6;
    printf("\n[ ");
    result = twoSum(n, nS, target, &rS);
    // result = twoSumHash(n, nS, target, &rS);
    for(i = 0; i < nS; i++){printf("%d ", result[i]);}
    printf("]\n");

    free(result);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// gcc threesum.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 3000


void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int arr[], int lower, int upper){
    int i = (lower - 1);
    int pivot = arr[upper];
    int j;
    for(j = lower; j < upper; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[upper]);
    return (i + 1);
}

void quickSort(int arr[], int lower, int upper){
    if(upper > lower){
        int partitionIndex = partition(arr, lower, upper);
        quickSort(arr, lower, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, upper);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    /* Given an integer array nums, returns all the
     * triplets [nums[i], nums[j], nums[k]] such that
     * i != j, i != k, and j != k,
     * and nums[i] + nums[j] + nums[k] == 0. The solution
     * set must not contain duplicate triplets. */
    *returnSize = 0;
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));
    int **result = malloc(numsSize * numsSize * sizeof(int*));

    quickSort(nums, 0, (numsSize - 1));
    int minIdx, maxIdx, check;
    int i;
    for(i = 0; i < (numsSize - 2); i++){
        minIdx = (i + 1), maxIdx = (numsSize - 1);
        if((i > 0) && (nums[i] == nums[i - 1])){continue;}
        while(minIdx < maxIdx){
            check = nums[i] + nums[minIdx] + nums[maxIdx];
            if(check < 0){minIdx++;}
            else if(check > 0){maxIdx--;}
            else{
                result[*returnSize] = malloc(3 * sizeof(int));
                (*returnColumnSizes)[*returnSize] = 3;
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[minIdx];
                result[*returnSize][2] = nums[maxIdx];
                *returnSize += 1;
                minIdx++;
                while((nums[minIdx] == nums[minIdx - 1]) && (minIdx < maxIdx)){minIdx++;}
            }
        }
    }
    // *returnColumnSizes = malloc(*returnSize * sizeof(int));
    // for(i = 0; i < *returnSize; i++){(*returnColumnSizes)[i] = 3;}
    return result;
}


// TESTS
int main(void){
    int returnVal = 0;
    int *n = malloc(MAX * sizeof(int));
    int nS;
    int rS = 0, *rCS = 0;
    int **result;
    int i, j;

    // assert [-1, 0, 1, 2, -1, -4] == [[-1, -1, 2], [-1, 0, 1]]
    n[0] = -1, n[1] = 0, n[2] = 1, n[3] = 2, n[4] = -1, n[5] = -4;
    nS = 5;
    result = threeSum(n, nS, &rS, &rCS);
    for(i = 0; i < rS; i++){
        printf("[ ");
        for(j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("] \n");
        free(result[i]);
    }
    free(rCS);
    free(result);

    // assert [] == []
    nS = 0;
    result = threeSum(n, nS, &rS, &rCS);
    for(i = 0; i < rS; i++){
        printf("[ ");
        for(j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("] \n");
        free(result[i]);
    }
    free(rCS);
    free(result);

    // assert [0] == []
    n[0] = 0;
    nS = 1;
    result = threeSum(n, nS, &rS, &rCS);
    for(i = 0; i < rS; i++){
        printf("[ ");
        for(j = 0; j < 3; j++){
            printf("%d ", result[i][j]);
        }
        printf("] \n");
        free(result[i]);
    }
    free(rCS);
    free(result);

    free(n);
    return returnVal;
}

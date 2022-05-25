#include <stdio.h>

// gcc maximum_product_subarray.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


int maxProduct(int* nums, int numsSize){
    /* Given an integer array nums, find a
     * contiguous non-empty subarray within the
     * array that has the largest product, and
     * return the product. */
    int min_v = 1, max_v = 1, current = 0, temp_v = 0;
    int product = nums[0];
    int tempArr[2] = {0};
    int i;
    int j;
    for(i = 0; i < numsSize; i++){
        if(nums[i] > product){product = nums[i];}
    }
    for(i = 0; i < numsSize; i++){
        current = max_v * nums[i];
        temp_v = nums[i];
        tempArr[0] = nums[i] * max_v;
        tempArr[1] = nums[i] * min_v;
        for(j = 0; j < 2; j++){
            if(tempArr[j] > temp_v){temp_v = tempArr[j];}
            max_v = temp_v;
        }
        temp_v = nums[i];
        tempArr[0] = current;
        for(j = 0; j < 2; j++){
            if(tempArr[j] < temp_v){temp_v = tempArr[j];}
            min_v = temp_v;
        }
        if(max_v > product){product = max_v;}
    }
    return product;
}


// TESTS
int main(void){
    int returnValue = 0;

    // assert [2, 3, -2, 4] == 6
    int s[4] = {2, 3, -2, 4};
    int n = sizeof(s) / sizeof(int);
    int result = maxProduct(s, n);
    printf("\n%d", result);
    if(result != 6){returnValue = 1;}

    // assert [-2, 0, -1] == 0
    int sTwo[3] = {-2, 0, -1};
    int nTwo = sizeof(sTwo) / sizeof(int);
    int resultTwo = maxProduct(sTwo, nTwo);
    printf("\n%d", resultTwo);
    if(resultTwo != 0){returnValue = 1;}

    // assert [-3, -1, -1] == 3
    int sThree[3] = {-3, -1, -1};
    int nThree = sizeof(sThree) / sizeof(int);
    int resultThree = maxProduct(sThree, nThree);
    printf("\n%d", resultThree);
    if(resultThree != 3){returnValue = 1;}

    // assert [-2, -3, 7] == 42
    int sFour[3] = {-2, -3, 7};
    int nFour = sizeof(sFour) / sizeof(int);
    int resultFour = maxProduct(sFour, nFour);
    printf("\n%d", resultFour);
    if(resultFour != 42){returnValue = 1;}

    printf("\n");
    return returnValue;
}

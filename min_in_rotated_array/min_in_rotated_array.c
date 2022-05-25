#include <stdio.h>
#include <stdlib.h>

// gcc min_in_rotated_array.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 5001


int findMin(int* nums, int numsSize){
    /* Suppose an array of length n sorted
     *in ascending order is rotated between
     *1 and n times. Given the sorted
     *rotated array nums of unique elements,
     *return the minimum element of this
     *array. */
    int i;
    for(i = (numsSize - 1); i > 0; i--){
        if((nums[i] - 1) < (nums[i - 1])){return nums[i];}
    }
    return nums[0];
}


//TESTS
int main(void){
    int returnVal = 0;
    int *a = malloc(sizeof(int) * MAX);
    int s;
    int result;

    // [1, 2, 3, 4, 5]
    a[0] = 1, a[1] = 2, a[2] = 3, a[3] = 5;
    s = 4;
    result = findMin(a, s);
    if(result != 1){returnVal = 1;}
    printf("\n%d", result);

    // [3, 4, 5, 1, 2]
    a[0] = 3, a[1] = 4, a[2] = 5, a[3] = 1, a[4] = 2;
    s = 5;
    result = findMin(a, s);
    if(result != 1){returnVal = 1;}
    printf("\n%d", result);

    // [4, 5, 6, 7, 0, 1, 2]
    a[0] = 4, a[1] = 5, a[2] = 6, a[3] = 7, a[4] = 0, a[5] = 1; a[6] = 2;
    s = 7;
    result = findMin(a, s);
    if(result != 0){returnVal = 1;}
    printf("\n%d", result);

    // [11, 13, 15, 17]
    a[0] = 11, a[1] = 13, a[2] = 15, a[3] = 17;
    s = 4;
    result = findMin(a, s);
    if(result != 11){returnVal = 1;}
    printf("\n%d", result);

    free(a);
    printf("\n");
    return returnVal;
}

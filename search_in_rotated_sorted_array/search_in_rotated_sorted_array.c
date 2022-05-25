#include <stdio.h>
#include <stdlib.h>

// gcc search_in_rotated_sorted_array.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 5001

int search(int* nums, int numsSize, int target){
    /* Suppose an array of length n sorted in
     * ascending order is rotated between 1 and n times.
     * Given the array nums after the possible rotation
     * and an integer target, return the index of target
     * if it is in nums, or -1 if it is not in nums. */
    if(numsSize == 0){return -1;}
    int left = 0, right = (numsSize - 1);
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] == target){return mid;}
        if(nums[left] <= nums[mid]){
            if((nums[left] <= target) && (target <= nums[mid])){right = (mid - 1);}
            else{left = (mid + 1);}
        }
        else{
            if((nums[mid] <= target) && (target <= nums[right])){left = (mid + 1);}
            else{right = (mid - 1);}
        }
    }
    return -1;
}


// TESTS
int main(void){
    int returnVal = 0;
    int *a = malloc(MAX * sizeof(int));
    int s, t;
    int result;

    // [5, 1, 3], 5) == 0
    a[0] = 5, a[1] = 1, a[2] = 3;
    s = 3,t = 5;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != 0){returnVal = 1;}

    // [4, 5, 6, 7, 0, 1, 2], 0) == 4
    a[0] = 4, a[1] = 5, a[2] = 6, a[3] = 7, a[4] = 0, a[5] = 1, a[6] = 2;
    s = 7, t = 0;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != 4){returnVal = 1;}

    // [4, 5, 6, 7, 0, 1, 2], 1) == 5
    a[0] = 4, a[1] = 5, a[2] = 6, a[3] = 7, a[4] = 0, a[5] = 1, a[6] = 2;
    s = 7, t = 1;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != 5){returnVal = 1;}

    // [4, 5, 6, 7, 0, 1, 2], 3) == -1
    a[0] = 4, a[1] = 5, a[2] = 6, a[3] = 7, a[4] = 0, a[5] = 1, a[6] = 2;
    s = 7, t = 3;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != -1){returnVal = 1;}

    // [1], 0) == -1
    a[0] = 1;
    s = 1, t = 0;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != -1){returnVal = 1;}

    // [1, 3], 1) == 0
    a[0] = 1, a[1] = 3;
    s = 2, t = 1;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != 0){returnVal = 1;}

    // [1, 3], 3) == 1
    a[0] = 1, a[1] = 3;
    s = 2, t = 3;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != 1){returnVal = 1;}

    // [1], 1) == 0
    a[0] = 1;
    s = 1, t = 1;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != 0){returnVal = 1;}

    // [1], 2) == -1
    a[0] = 1;
    s = 1, t = 2;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != -1){returnVal = 1;}

    // [], 7) == -1
    a[0] = 0;
    s = 0, t = 7;
    result = search(a, s, t);
    printf("\n%d", result);
    if(result != -1){returnVal = 1;}

    free(a);
    printf("\n");
    return returnVal;
}

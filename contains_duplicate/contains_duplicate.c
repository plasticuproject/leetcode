#include <stdio.h>
#include <stdbool.h>
#include "uthash.h"

// gcc contains_duplicate.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


typedef struct {
    int key, index;
    UT_hash_handle hh;
}hashEntry;


bool containsDuplicate(int* nums, int numsSize){
    /* Given an integer array nums, returns true if
     * any value appears at least twice in the array,
     * and return false if every element is distinct. */
    hashEntry *memo = NULL, *elem, *tmp;
    int i;
    bool returnValue = false;
    for(i = 0; i < numsSize; i++){
        HASH_FIND_INT(memo, &nums[i], elem);
        if(elem){
            returnValue = true;
            break;
        }
        else{
            elem = malloc(sizeof(hashEntry));
            elem->key = nums[i];
            elem->index = i;
            HASH_ADD_INT(memo, key, elem);
        }
    }
    HASH_ITER(hh, memo, elem, tmp){
        HASH_DEL(memo, elem);
        free(elem);
    }
    HASH_CLEAR(hh, memo);
    return returnValue;
}


// TESTS
int main(void){
    int returnVal = 0;

    // assert [1, 2, 3, 1] == true
    int n[4] = {1, 2, 3, 1};
    int s = sizeof(n) / sizeof(int);
    bool result = containsDuplicate(n, s);
    if(result == true){printf("true\n");}
    else{printf("false\n");returnVal = 1;}

    // assert [1, 2, 3, 4] == true
    int nTwo[4] = {1, 2, 3, 4};
    int sTwo = sizeof(n) / sizeof(int);
    bool resultTwo = containsDuplicate(nTwo, sTwo);
    if(resultTwo == true){printf("true\n");}
    else{printf("false\n");returnVal = 1;}

    // assert [1, 5, -2, -4, 0] == false
    int nThree[5] = {1, 5, -2, -4, 0};
    int sThree = sizeof(n) / sizeof(int);
    bool resultThree = containsDuplicate(nThree, sThree);
    if(resultThree == true){printf("true\n");}
    else{printf("false\n");returnVal = 1;}

    return returnVal;
}

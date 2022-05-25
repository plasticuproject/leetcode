#include <stdio.h>

// gcc sum_of_two_integers.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


int getSum(int a, int b){
    /* Given two integers a and b,
     * returns the sum of the two integers
     * without using the operators + and -. */
    unsigned int tmp;
    while(b){
        tmp = (unsigned int)(a & b) << 1;
        a ^= b;
        b = tmp;
    }
    return a;
}


// TESTS
int main(void){
    int returnVal = 0;
    int result;

    // assert (1, 2) == 3
    result = getSum(1, 2);
    printf("\n%d", result);
    if(result != 3){returnVal = 1;}

    // assert (2, 3) = 5
    result = getSum(2, 3);
    printf("\n%d", result);
    if(result != 5){returnVal = 1;}

    // assert (-1, 3) = 2
    result = getSum(-1, 3);
    printf("\n%d", result);
    if(result != 2){returnVal = 1;}

    // assert (-1, 1) = 0
    result = getSum(-1, 1);
    printf("\n%d", result);
    if(result != 0){returnVal = 1;}

    printf("\n");
    return returnVal;
}

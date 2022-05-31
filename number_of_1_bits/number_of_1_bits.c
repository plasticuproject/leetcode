#include <stdio.h>

// gcc number_of_1_bits.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


int hammingWeight(__uint32_t n) {
    /* Takes an unsigned integer and
    returns the number of '1' bits it has. */
    int c = 0;
    while(n){
        n &= (n - 1);
        c++;
        // or:
        // c += n % 2
        // n = n >> 1
    }
    return c;
}


// TESTS
int main(void){
    int returnVal = 0;
    __uint32_t n;
    int result;

    // assert 00000000000000000000000000001011 == 3
    n = 13;
    result = hammingWeight(n);
    printf("\n%d", result);
    if(result != 3){returnVal = 1;}

    // assert 00000000000000000000000010000000 = 1
    n = 128;
    result = hammingWeight(n);
    printf("\n%d", result);
    if(result != 1){returnVal = 1;}

    // assert 11111111111111111111111111111101 == 31
    n = 4294967293;
    result = hammingWeight(n);
    printf("\n%d", result);
    if(result != 31){returnVal = 1;}

    printf("\n");
    return returnVal;
}

#include <stdio.h>
#include <stdlib.h>

// gcc container_with_most_water.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 100000


int maxArea(int* height, int heightSize){
    /* Given an integer array height of
     * length n. There are n vertical lines
     * drawn such that the two endpoints of the
     * ith line are (i, 0) and (i, height[i]).
     * Finds two lines that together with the
     * x-axis form a container, such that the
     * container contains the most water and
     * returns the maximum amount of water a
     * container can store. */
    int minIdx = 0, maxIdx = (heightSize - 1);
    int minHeight, area;
    int res = 0;
    while(minIdx < maxIdx){
        minHeight = (height[minIdx] < height[maxIdx]) ? height[minIdx] : height[maxIdx];
        area = minHeight * (maxIdx - minIdx);
        if(area > res){res = area;}
        if(height[minIdx] <= height[maxIdx]){minIdx++;}
        else{maxIdx--;}
    }
    return res;
}


// TESTS
int main(void){
    int returnVal = 0;
    int *n = malloc(MAX * sizeof(int));
    int nS;
    int result;

    // assert [1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
    n[0] = 1, n[1] = 8, n[2] = 6, n[3] = 2, n[4] = 5;
    n[5] = 4, n[6] = 8, n[7] = 3, n[8] = 7;
    nS = 9;
    result = maxArea(n, nS);
    printf("\n%d", result);
    if(result != 49){returnVal = 1;}

    // assert [1, 1] == 1
    n[0] = 1, n[1] = 1;
    nS = 2;
    result = maxArea(n, nS);
    printf("\n%d", result);
    if(result != 1){returnVal = 1;}

    printf("\n");
    free(n);
    return returnVal;

}

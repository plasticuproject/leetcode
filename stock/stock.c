#include <stdio.h>

// gcc stock.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


int maxProfit(int* prices, int pricesSize){
     /* Given an array prices where prices[i] is the
      * price of a given stock on the ith day, returns
      * the maximum profit you can achieve from a
      * single transaction.
     */
    int current = 0, nxt = 1;
    int profit = 0, maximumProfit = 0;
    while(nxt < pricesSize){
        if(prices[current] < prices[nxt]){
            profit = prices[nxt] - prices[current];
            if(profit > maximumProfit){
                maximumProfit = profit;
            }
        }
        else {current = nxt;}
        nxt++;
    }
    return maximumProfit;
}


// TESTS
int main(void){
    int returnVal = 0;

    // assert [7, 1, 5, 3, 6, 4] == 5
    int p[6] = {7, 1, 5, 3, 6, 4};
    int s = sizeof(p) / sizeof(int);
    int result = maxProfit(p, s);
    printf("\n%d", result);
    if(result != 5){returnVal = 1;}

    printf("\n");
    return returnVal;
}

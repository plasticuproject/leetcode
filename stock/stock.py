#!/usr/bin/env python3
"""stock.py"""
from typing import List
from timeit import timeit


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """Given an array prices where prices[i] is the
        price of a given stock on the ith day, returns
        the maximum profit you can achieve from a
        single transaction."""
        low = prices[0]
        high = low
        buy, sell, day = 1, 1, 1
        for day, price in enumerate(prices[1:], start=1):
            if price < low:
                low, high = price, price
                buy = day
            if price > high:
                high = price
                sell = day
        if buy < sell:
            return high - low
        return 0

    def bettermaxProfit(self, prices: List[int]) -> int:
        """Given an array prices where prices[i] is the
        price of a given stock on the ith day, returns
        the maximum profit you can achieve from a
        single transaction."""
        current, nxt, max_profit = 0, 1, 0
        while nxt < len(prices):
            if prices[current] < prices[nxt]:
                profit = prices[nxt] - prices[current]
                if profit > max_profit:
                    max_profit = profit
            else:
                current = nxt
            nxt += 1
        return max_profit


assert Solution().maxProfit([7, 1, 5, 3, 6, 4]) == 5
assert Solution().maxProfit([7, 6, 4, 3, 1]) == 0
assert Solution().bettermaxProfit([7, 1, 5, 3, 6, 4]) == 5
assert Solution().bettermaxProfit([7, 6, 4, 3, 1]) == 0

X = timeit(lambda: Solution().maxProfit([7, 1, 5, 3, 6, 4]), number=1000000)
print(X)

Y = timeit(lambda: Solution().bettermaxProfit([7, 1, 5, 3, 6, 4]),
           number=1000000)
print(Y)

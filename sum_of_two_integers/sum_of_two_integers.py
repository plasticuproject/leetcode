#!/usr/bin/env python3
"""sum_of_two_integers.py"""
from timeit import timeit


class Solution:
    def getSum(self, a: int, b: int) -> int:
        """Given two integers a and b,
        returns the sum of the two integers
        without using the operators + and -."""
        mask = 0xffffffff
        while b & mask:
            a, b = (a ^ b), (a & b) << 1
        return a & mask if b > 0 else a


assert Solution().getSum(1, 2) == 3
assert Solution().getSum(2, 3) == 5
X = timeit(lambda: Solution().getSum(1, 2), number=1000000)
print(X)

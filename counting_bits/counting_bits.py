#!/usr/bin/env python3
"""counting_bits.py"""
from typing import List
from timeit import timeit


class Solution:
    def countBits(self, n: int) -> List[int]:
        """Given an integer n, returns an
        array ans of length n + 1 such that
        for each i (0 <= i <= n), ans[i] is
        the number of 1's in the binary
        representation of i."""
        ans = [0] * (n + 1)
        offset = 1
        for i in range(1, n + 1):
            if i == offset * 2:
                offset = i
            ans[i] = 1 + ans[i - offset]
        return ans


assert Solution().countBits(2) == [0, 1, 1]
assert Solution().countBits(5) == [0, 1, 1, 2, 1, 2]

X = timeit(lambda: Solution().countBits(5), number=1000000)
print(X)

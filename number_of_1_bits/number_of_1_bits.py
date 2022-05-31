#!/usr/bin/env python3
"""number_of_1_bits.py"""
from timeit import timeit


class Solution:
    def hammingWeight(self, n: int) -> int:
        """Takes an unsigned integer and
        returns the number of '1' bits it has."""
        c = 0
        while n:
            c += n % 2
            n = n >> 1
        return c

    def hammingWeightTwo(self, n: int) -> int:
        """Takes an unsigned integer and
        returns the number of '1' bits it has."""
        c = 0
        while n:
            n &= (n - 1)
            c += 1
        return c


# n = 00000000000000000000000000001011
assert Solution().hammingWeight(13) == 3
# n = 00000000000000000000000010000000
assert Solution().hammingWeight(128) == 1
# n = 11111111111111111111111111111101
assert Solution().hammingWeight(4294967293) == 31

# n = 00000000000000000000000000001011
assert Solution().hammingWeightTwo(13) == 3
# n = 00000000000000000000000010000000
assert Solution().hammingWeightTwo(128) == 1
# n = 11111111111111111111111111111101
assert Solution().hammingWeightTwo(4294967293) == 31

X = timeit(lambda: Solution().hammingWeight(4294967293), number=1000000)
print(X)
Y = timeit(lambda: Solution().hammingWeightTwo(4294967293), number=1000000)
print(Y)

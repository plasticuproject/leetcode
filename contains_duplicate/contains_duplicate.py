#!/usr/bin/env python3
"""contains_duplicate.py"""
from typing import List
from timeit import timeit


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """Given an integer array nums, returns true if
        any value appears at least twice in the array,
        and return false if every element is distinct."""
        memo = {}
        for i, n in enumerate(nums):
            if n in memo:
                return True
            memo[n] = i
        return False

    def countcontainsDuplicate(self, nums: List[int]) -> bool:
        """Given an integer array nums, returns true if
        any value appears at least twice in the array,
        and return false if every element is distinct."""
        memo = {}
        c = 0
        for n in nums:
            if n in memo:
                return True
            memo[n] = c
            c += 1
        return False


assert Solution().containsDuplicate([1, 2, 3, 1])
assert not Solution().containsDuplicate([1, 2, 3, 4])
assert Solution().containsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2])

X = timeit(
    lambda: Solution().containsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]),
    number=1000000)
print(X)
Y = timeit(
    lambda: Solution().countcontainsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]),
    number=1000000)
print(Y)

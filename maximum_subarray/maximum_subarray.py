#!/usr/bin/env python3
"""maximum_subarray.py"""
from typing import List
from timeit import timeit


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """Given an integer array nums, find the
        contiguous subarray (containing at least
        one number) which has the largest sum and
        return its sum."""
        previous = nums[0]
        new_sum = 0
        for num in nums:
            if new_sum < 0:
                new_sum = 0
            new_sum += num
            if new_sum > previous:
                previous = new_sum
        return previous


assert Solution().maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
assert Solution().maxSubArray([1]) == 1
assert Solution().maxSubArray([5, 4, -1, 7, 8]) == 23

X = timeit(lambda: Solution().maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]),
           number=1000000)
print(X)

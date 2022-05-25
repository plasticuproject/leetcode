#!/usr/bin/env/ python3
"""min_in_rotated_array.py"""

from typing import List
from timeit import timeit


class Solution:
    def findMin(self, nums: List[int]) -> int:
        """Suppose an array of length n sorted
        in ascending order is rotated between
        1 and n times. Given the sorted
        rotated array nums of unique elements,
        return the minimum element of this
        array."""
        for i in range(len(nums) - 1, 0, -1):
            if (nums[i] - 1) < nums[i - 1]:
                return nums[i]
        return nums[0]


assert Solution().findMin([3, 4, 5, 1, 2]) == 1
assert Solution().findMin([4, 5, 6, 7, 0, 1, 2]) == 0
assert Solution().findMin([11, 13, 15, 17]) == 11

X = timeit(lambda: Solution().findMin([11, 13, 15, 17]), number=1000000)
print(X)

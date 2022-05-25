#!/usr/bin/env python3
"""threesum.py"""
from typing import List
from timeit import timeit


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """Given an integer array nums, returns all the
        triplets [nums[i], nums[j], nums[k]] such that
        i != j, i != k, and j != k,
        and nums[i] + nums[j] + nums[k] == 0. The solution
        set must not contain duplicate triplets."""
        ret = []
        nums.sort()
        length = len(nums) - 1
        for i in range(length - 1):
            min_idx, max_idx = (i + 1), length
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            while min_idx < max_idx:
                check = nums[i] + nums[min_idx] + nums[max_idx]
                if check < 0:
                    min_idx += 1
                elif check > 0:
                    max_idx -= 1
                else:
                    ret.append([nums[i], nums[min_idx], nums[max_idx]])
                    min_idx += 1
                    while ((nums[min_idx] == nums[min_idx - 1])
                           and (min_idx < max_idx)):
                        min_idx += 1
        return ret


assert Solution().threeSum([-1, 0, 1, 2, -1, -4]) == [[-1, -1, 2], [-1, 0, 1]]
assert Solution().threeSum([]) == []
assert Solution().threeSum([0]) == []

X = timeit(lambda: Solution().threeSum([-1, 0, 1, 2, -1, -4]), number=1000000)
print(X)

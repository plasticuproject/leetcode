#!/usr/bin/env python3
"""product_of_array_accept_self.py"""
from typing import List
from timeit import timeit


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """Given an integer array nums, return an array answer
        such that answer[i] is equal to the product of all the
        elements of nums except nums[i]."""
        nums_length = len(nums)
        left, right = 1, 1
        answer = [1] * nums_length
        for i in range(nums_length):
            answer[i] *= left
            answer[~i] *= right
            left *= nums[i]
            right *= nums[~i]
        return answer


assert Solution().productExceptSelf([1, 2, 3, 4]) == [24, 12, 8, 6]
assert Solution().productExceptSelf([-1, 1, 0, -3, 3]) == [0, 0, 9, 0, 0]

X = timeit(lambda: Solution().productExceptSelf([1, 2, 3, 4]), number=1000000)
print(X)

#!/usr/bin/env python3
"""maximum_product_subarray.py"""
from typing import List
from timeit import timeit


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        """Given an integer array nums, find a
        contiguous non-empty subarray within the
        array that has the largest product, and
        return the product"""
        product = nums[0]
        for i in nums:
            if i > product:
                product = i
        min_v, max_v = 1, 1
        for num in nums:
            current = max_v * num
            temp_v = num
            for i in [num * max_v, num * min_v]:
                if i > temp_v:
                    temp_v = i
                max_v = temp_v
            temp_v = num
            for i in [current, num * min_v]:
                if i < temp_v:
                    temp_v = i
                min_v = temp_v
            if max_v > product:
                product = max_v
        return product

    def fmaxProduct(self, nums: List[int]) -> int:
        # O(n)/O(1) : Time/Memory
        res = max(nums)
        curMin, curMax = 1, 1

        for n in nums:

            tmp = curMax * n
            curMax = max(n * curMax, n * curMin, n)
            curMin = min(tmp, n * curMin, n)
            res = max(res, curMax)
        return res


assert Solution().maxProduct([2, 3, -2, 4]) == 6
assert Solution().maxProduct([-2, 0, -1]) == 0
assert Solution().maxProduct([-3, -1, -1]) == 3
assert Solution().maxProduct([-2, -3, 7]) == 42

X = timeit(lambda: Solution().maxProduct([2, 3, -2, 4]), number=1000000)
print(X)

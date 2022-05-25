#!/usr/bin/env/ python3
"""search_in_rotated_sorted_array.py"""

from typing import List
from timeit import timeit


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """Suppose an array of length n sorted in
        ascending order is rotated between 1 and n times.
        Given the array nums after the possible rotation
        and an integer target, return the index of target
        if it is in nums, or -1 if it is not in nums."""
        if not nums:
            return -1
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            if nums[left] <= nums[mid]:
                if nums[left] <= target <= nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] <= target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1


assert Solution().search([5, 1, 3], 5) == 0
assert Solution().search([4, 5, 6, 7, 0, 1, 2], 0) == 4
assert Solution().search([4, 5, 6, 7, 0, 1, 2], 1) == 5
assert Solution().search([4, 5, 6, 7, 0, 1, 2], 3) == -1
assert Solution().search([1], 0) == -1
assert Solution().search([1, 3], 1) == 0
assert Solution().search([1, 3], 3) == 1
assert Solution().search([1], 1) == 0
assert Solution().search([1], 2) == -1
assert Solution().search([], 7) == -1

X = timeit(lambda: Solution().search([4, 5, 6, 7, 0, 1, 2], 0), number=1000000)
print(X)

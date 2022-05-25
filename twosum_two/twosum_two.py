#!/usr/bin/env python3
"""twosum_two.py"""
from typing import List
from timeit import timeit


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        """Given a 1-indexed array of integers numbers that is
        already sorted in non-decreasing order, finds two numbers
        such that they add up to the target number. These two
        numbers are numbers[index1] and numbers[index2]
        where 1 <= index1 < index2 <= numbers.length.
        Returns the indices of the two numbers, index1 and index2,
        added by one as an integer array [index1, index2] of
        length 2."""
        min_idx, max_idx = 0, len(numbers) - 1
        check = numbers[min_idx] + numbers[max_idx]
        while check != target:
            if check < target:
                min_idx += 1
            else:
                max_idx -= 1
            check = numbers[min_idx] + numbers[max_idx]
        return [(min_idx + 1), (max_idx + 1)]


assert Solution().twoSum([2, 7, 11, 15], 9) == [1, 2]
assert Solution().twoSum([2, 3, 4], 6) == [1, 3]
assert Solution().twoSum([-1, 0], -1) == [1, 2]

X = timeit(lambda: Solution().twoSum([2, 7, 11, 15], 9), number=1000000)
print(X)

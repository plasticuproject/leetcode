from timeit import timeit
from typing import List, Tuple
"""twosum.py"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """Given an array of integers nums and an integer target, returns
        indices of the two numbers that add up to target. Assumes that each
        input will have exactly one solution, and does not use the same
        element twice."""
        memo = {}
        index = 0
        for num in nums:
            sub = target - num
            if sub in memo:
                return [memo[sub], index]
            memo[num] = index
            index += 1


assert Solution().twoSum([2, 7, 11, 15], 9) == [0, 1]

X = timeit(lambda: Solution().twoSum([2, 7, 11, 15], 9), number=1000000)
print(X)

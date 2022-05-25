#!/usr/bin/env python3
"""container_with_most_water.py"""
from typing import List
from timeit import timeit


class Solution:
    def maxArea(self, height: List[int]) -> int:
        """Given an integer array height of
        length n. There are n vertical lines
        drawn such that the two endpoints of the
        ith line are (i, 0) and (i, height[i]).
        Finds two lines that together with the
        x-axis form a container, such that the
        container contains the most water and
        returns the maximum amount of water a
        container can store."""
        min_idx, max_idx = 0, (len(height) - 1)
        res = 0
        while min_idx < max_idx:
            min_height = height[min_idx] if height[min_idx] < height[
                max_idx] else height[max_idx]
            area = min_height * (max_idx - min_idx)
            res = area if area > res else res
            if height[min_idx] <= height[max_idx]:
                min_idx += 1
            else:
                max_idx -= 1
        return res


assert Solution().maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
assert Solution().maxArea([1, 1]) == 1

X = timeit(lambda: Solution().maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]),
           number=1000000)
print(X)

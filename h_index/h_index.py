#!/usr/bin/env python3
"""h_index.py"""
from typing import List
from timeit import timeit


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        """Given an array of integers citations
        where citations[i] is the number of
        citations a researcher received for their
        ith paper, return compute the researcher's
        h-index."""
        citations.sort()
        length: int = len(citations)
        for index in range(length):
            if citations[index] >= length - index:
                return length - index
        return 0


assert Solution().hIndex([3, 0, 6, 1, 5]) == 3
assert Solution().hIndex([1, 3, 1]) == 1

X = timeit(lambda: Solution().hIndex([3, 0, 6, 1, 5]), number=1000000)
print(X)

#!/usr/bin/env python3
"""transpose_matrix.py"""
from typing import List
from timeit import timeit


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        """Given a 2D integer array matrix,
        returns the transpose of matrix."""
        return [[matrix[j][i] for j in range(len(matrix))]
                for i in range(len(matrix[0]))]

    def transpose2(self, matrix: List[List[int]]) -> List[List[int]]:
        """Given a 2D integer array matrix,
        returns the transpose of matrix."""
        return list(map(list, zip(*matrix)))


IN = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
OUT = [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
assert Solution().transpose2(IN) == OUT

IN = [[1, 2, 3], [4, 5, 6]]
OUT = [[1, 4], [2, 5], [3, 6]]
assert Solution().transpose2(IN) == OUT

X = timeit(lambda: Solution().transpose(IN), number=1000000)
print(X)
Y = timeit(lambda: Solution().transpose2(IN), number=1000000)
print(Y)

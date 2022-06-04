#!/usr/bin/env python3
"""range_sum_query_2d_immutable.py"""
from typing import List
from timeit import timeit


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        """Initializes the object with the
        integer matrix matrix and pre-computes
        all matrix subset sums into
        self.sub_matrices."""
        self.matrix = matrix
        rows, cols = len(matrix) + 1, len(matrix[0]) + 1
        self.sub_matrices = [[0] * cols for _ in range(rows)]
        for row in range(1, rows):
            for col in range(1, cols):
                self.sub_matrices[row][col] = (
                    self.sub_matrices[row - 1][col] +
                    self.sub_matrices[row][col - 1] -
                    self.sub_matrices[row - 1][col - 1] +
                    matrix[row - 1][col - 1])

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        """Returns the sum of the elements of matrix inside the rectangle
        defined by its upper left corner (row1, col1) and lower right corner
        (row2, col2)."""
        return (self.sub_matrices[row2 + 1][col2 + 1] -
                self.sub_matrices[row2 + 1][col1] -
                self.sub_matrices[row1][col2 + 1] +
                self.sub_matrices[row1][col1])

    def sumRegion2(self, row1: int, col1: int, row2: int, col2: int) -> int:
        """Returns the sum of the elements of matrix inside the rectangle
        defined by its upper left corner (row1, col1) and lower right corner
        (row2, col2)."""
        sub_matrix = 0
        for i in self.matrix[row1:(row2 + 1)]:
            sub_matrix += sum(i[col1:(col2 + 1)])
        return sub_matrix


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)

TEST_MATRIX = [[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5],
               [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]
numMatrix = NumMatrix(TEST_MATRIX)

assert numMatrix.sumRegion(2, 1, 4, 3) == 8
assert numMatrix.sumRegion(1, 1, 2, 2) == 11
assert numMatrix.sumRegion(1, 2, 2, 4) == 12

assert numMatrix.sumRegion2(2, 1, 4, 3) == 8
assert numMatrix.sumRegion2(1, 1, 2, 2) == 11
assert numMatrix.sumRegion2(1, 2, 2, 4) == 12

X = timeit(lambda: numMatrix.sumRegion(1, 2, 2, 4), number=1000000)
Y = timeit(lambda: numMatrix.sumRegion2(1, 2, 2, 4), number=1000000)
print(X)
print(Y)

"""test_h_index.py"""

from typing import List
from timeit import timeit
from leetcode import h_index  # C Extension


def native_h_index(citations: List[int]) -> int:
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


# # TESTS

assert native_h_index([3, 0, 6, 1, 5]) == 3
assert native_h_index([1, 3, 1]) == 1

assert h_index([3, 0, 6, 1, 5]) == 3
assert h_index([1, 3, 1]) == 1

X = timeit(lambda: native_h_index([3, 0, 6, 1, 5]), number=1000000)
Y = timeit(lambda: h_index([3, 0, 6, 1, 5]), number=1000000)

print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

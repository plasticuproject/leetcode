"""test_max_area.py"""
from typing import List
from timeit import timeit
from leetcode import max_area  # C extension


def native_max_area(height: List[int]) -> int:
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
        min_height = height[
            min_idx] if height[min_idx] < height[max_idx] else height[max_idx]
        area = min_height * (max_idx - min_idx)
        res = area if area > res else res
        if height[min_idx] <= height[max_idx]:
            min_idx += 1
        else:
            max_idx -= 1
    return res


# # TESTS
assert native_max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
assert native_max_area([1, 1]) == 1

assert max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
assert max_area([1, 1]) == 1

X = timeit(lambda: native_max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]),
           number=1000000)
Y = timeit(lambda: max_area([1, 8, 6, 2, 5, 4, 8, 3, 7]), number=1000000)
print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

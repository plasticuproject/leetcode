"""test_find_min.py"""

from typing import List
from timeit import timeit
from leetcode import find_min  # C Extension


def native_find_min(nums: List[int]) -> int:
    """Suppose an array of length n sorted
    in ascending order is rotated between
    1 and n times. Given the sorted
    rotated array nums of unique elements,
    return the minimum element of this
    array."""
    for i in range(len(nums) - 1, 0, -1):
        if (nums[i] - 1) < nums[i - 1]:
            return nums[i]
    return nums[0]


assert native_find_min([3, 4, 5, 1, 2]) == 1
assert native_find_min([4, 5, 6, 7, 0, 1, 2]) == 0
assert native_find_min([11, 13, 15, 17]) == 11

assert find_min([3, 4, 5, 1, 2]) == 1
assert find_min([4, 5, 6, 7, 0, 1, 2]) == 0
assert find_min([11, 13, 15, 17]) == 11

X = timeit(lambda: native_find_min([11, 13, 15, 17]), number=1000000)
Y = timeit(lambda: find_min([11, 13, 15, 17]), number=1000000)

print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

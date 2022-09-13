"""test_max_subarray.py"""

from typing import List
from timeit import timeit
from leetcode import max_subarray  # C Extension


def native_max_subarray(nums: List[int]) -> int:
    """Given an integer array nums, find the
    contiguous subarray (containing at least
    one number) which has the largest sum and
    return its sum."""
    previous = nums[0]
    new_sum = 0
    for num in nums:
        if new_sum < 0:
            new_sum = 0
        new_sum += num
        if new_sum > previous:
            previous = new_sum
    return previous


# # TESTS
assert native_max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
assert native_max_subarray([1]) == 1
assert native_max_subarray([5, 4, -1, 7, 8]) == 23

assert max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
assert max_subarray([1]) == 1
assert max_subarray([5, 4, -1, 7, 8]) == 23

X = timeit(lambda: native_max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]),
           number=1000000)
Y = timeit(lambda: max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4]),
           number=1000000)

print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

"""test_max_product.py"""

from typing import List
from timeit import timeit
from leetcode import max_product  # C Extension


def native_max_product(nums: List[int]) -> int:
    """Given an integer array nums, find a
    contiguous non-empty subarray within the
    array that has the largest product, and
    return the product"""
    product = nums[0]
    for i in nums:
        if i > product:
            product = i
    min_v, max_v = 1, 1
    for num in nums:
        current = max_v * num
        temp_v = num
        for i in [num * max_v, num * min_v]:
            if i > temp_v:
                temp_v = i
            max_v = temp_v
        temp_v = num
        for i in [current, num * min_v]:
            if i < temp_v:
                temp_v = i
            min_v = temp_v
        if max_v > product:
            product = max_v
    return product


# # TESTS
assert native_max_product([2, 3, -2, 4]) == 6
assert native_max_product([-2, 0, -1]) == 0
assert native_max_product([-3, -1, -1]) == 3
assert native_max_product([-2, -3, 7]) == 42

assert max_product([2, 3, -2, 4]) == 6
assert max_product([-2, 0, -1]) == 0
assert max_product([-3, -1, -1]) == 3
assert max_product([-2, -3, 7]) == 42

X = timeit(lambda: native_max_product([2, 3, -2, 4]), number=1000000)
Y = timeit(lambda: max_product([2, 3, -2, 4]), number=1000000)

print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

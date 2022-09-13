"""test_contains_duplicate.py"""

from typing import List
from timeit import timeit
from leetcode import contains_duplicate  # C extension


def native_contains_duplicate(nums: List[int]) -> bool:
    """Given an integer array nums, returns true if
    any value appears at least twice in the array,
    and return false if every element is distinct."""
    memo = {}
    c = 0
    for n in nums:
        if n in memo:
            return True
        memo[n] = c
        c += 1
    return False


# # TESTS
assert native_contains_duplicate([1, 2, 3, 1])
assert not native_contains_duplicate([1, 2, 3, 4])
assert native_contains_duplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2])

assert contains_duplicate([1, 2, 3, 1])
assert not contains_duplicate([1, 2, 3, 4])
assert contains_duplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2])

X = timeit(lambda: native_contains_duplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]),
           number=10000000)
Y = timeit(lambda: contains_duplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]),
           number=10000000)

print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

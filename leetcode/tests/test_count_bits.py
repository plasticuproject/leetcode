"""test_count_bits.py"""

from typing import List
from timeit import timeit
from leetcode import count_bits  # C Extension


def native_count_bits(num: int) -> List[int]:
    """Given an integer n, returns an
    array ans of length n + 1 such that
    for each i (0 <= i <= n), ans[i] is
    the number of 1's in the binary
    representation of i."""
    ans = [0] * (num + 1)
    offset = 1
    for i in range(1, num + 1):
        if i == offset * 2:
            offset = i
        ans[i] = 1 + ans[i - offset]
    return ans


# # TESTS
assert native_count_bits(2) == [0, 1, 1]
assert native_count_bits(5) == [0, 1, 1, 2, 1, 2]

assert count_bits(2) == [0, 1, 1]
assert count_bits(5) == [0, 1, 1, 2, 1, 2]

X = timeit(lambda: native_count_bits(5), number=1000000)
Y = timeit(lambda: count_bits(5), number=1000000)

print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

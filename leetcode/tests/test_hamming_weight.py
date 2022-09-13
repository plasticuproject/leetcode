"""test_hamming_weight.py"""

from timeit import timeit
from leetcode import hamming_weight  # C Extension


def native_hamming_weight(num: int) -> int:
    """Takes an unsigned integer and
    returns the number of '1' bits it has."""
    count = 0
    while num:
        count += num % 2
        num = num >> 1
        # or:
        # num &= (num - 1)
        # count += 1
    return count


# # TESTS
# n = 00000000000000000000000000001011
assert native_hamming_weight(13) == 3
# n = 00000000000000000000000010000000
assert native_hamming_weight(128) == 1
# n = 11111111111111111111111111111101
assert native_hamming_weight(4294967293) == 31

# n = 00000000000000000000000000001011
assert hamming_weight(13) == 3
# n = 00000000000000000000000010000000
assert hamming_weight(128) == 1
# n = 11111111111111111111111111111101
assert hamming_weight(4294967293) == 31

X = timeit(lambda: native_hamming_weight(4294967293), number=1000000)
Y = timeit(lambda: hamming_weight(4294967293), number=1000000)

print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

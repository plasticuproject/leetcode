"""test_letter_combinations_of_a_phone_number.py"""
from typing import List
from timeit import timeit
from leetcode import letter_combinations  # C Extension


def _mapper(digit: str) -> str:
    """Given a string representation
    of a number, returns a string of
    letters mapped to that number."""
    digit_int = ord(digit)
    digit_modifier = digit_int + 47 + (((digit_int + 50) % 50) * 2)
    result = ""
    if digit == "7":
        offset, count = 0, 4
    elif digit == "8":
        offset, count = 1, 4
    elif digit == "9":
        offset, count = 1, 5
    else:
        offset, count = 0, 3
    for i in range(offset, count):
        letter = digit_modifier + i
        result += chr(letter)
    return result


def native_letter_combinations(digits: str) -> List[str]:
    """Given a string containing digits from 2-9
    inclusive, returns all possible letter combinations
    that the number could represent."""
    if not digits:
        return []
    result = ['']
    for i in range(len(digits)):
        result = [j + k for j in result for k in _mapper(digits[i])]
    return result


# # TESTS
assert native_letter_combinations("") == []
assert native_letter_combinations("2") == ["a", "b", "c"]
assert native_letter_combinations("23") == [
    "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
]

assert letter_combinations("") == []
assert letter_combinations("2") == ["a", "b", "c"]
assert letter_combinations("23") == [
    "ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"
]

X = timeit(lambda: native_letter_combinations("23"), number=1000000)
Y = timeit(lambda: letter_combinations("23"), number=1000000)
print("Native Code Time     :", X)
print("C Extension Code Time:", Y)

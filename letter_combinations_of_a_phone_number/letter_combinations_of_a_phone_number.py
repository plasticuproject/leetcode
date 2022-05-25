#!/usr/bin/env python3
"""letter_combinations_of_a_phone_number.py"""
from typing import List
from timeit import timeit


class Solution:
    @staticmethod
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

    def letterCombinations(self, digits: str) -> List[str]:
        """Given a string containing digits from 2-9
        inclusive, returns all possible letter combinations
        that the number could represent."""
        if not digits:
            return []
        result = ['']
        for i in range(len(digits)):
            result = [j + k for j in result for k in self._mapper(digits[i])]
        return result


assert Solution().letterCombinations("") == []
assert Solution().letterCombinations("2") == ["a", "b", "c"]
assert Solution().letterCombinations("23") == [
    "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
]

X = timeit(lambda: Solution().letterCombinations("23"), number=1000000)
print(X)

#!/usr/bin/env python3
"""peeking_iterator.py"""

# Below is the interface for Iterator, which is already defined for you.


class Iterator:
    def __init__(self, nums):
        """
        Initializes an iterator object to the beginning of a list.
        :type nums: List[int]
        """
        self.nums = nums
        self.current = -1
        self.length = len(nums)

    def hasNext(self):
        """
        Returns true if the iteration has more elements.
        :rtype: bool
        """
        return self.current < self.length - 1

    def next(self):
        """
        Returns the next element in the iteration.
        :rtype: int
        """
        if self.current < self.length - 1:
            self.current += 1
            return self.nums[self.current]
        return None


class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.value = self.iterator.next()

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        return self.value

    def next(self):
        """
        :rtype: int
        """
        tmp = self.value
        self.value = self.iterator.next() if self.iterator.hasNext() else None
        return tmp

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.value != None


# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].

it = Iterator([1, 2, 3])
assert it.hasNext()
assert it.next() == 1
assert it.hasNext()
assert it.next() == 2
assert it.hasNext()
assert it.next() == 3
assert not it.hasNext()
assert not it.next()

peekingIterator = PeekingIterator(Iterator([1, 2, 3]))
assert peekingIterator.next() == 1
assert peekingIterator.peek() == 2
assert peekingIterator.next() == 2
assert peekingIterator.next() == 3
assert not peekingIterator.hasNext()

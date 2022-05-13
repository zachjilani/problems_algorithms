"""
Given an integer array nums where every element
appears three times except for one, which appears
exactly once. Find the single element and return it.

You must implement a solution with a linear runtime
complexity and use only constant extra space.
"""

def singleNumber(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    return collections.Counter(nums).most_common()[-1][0]

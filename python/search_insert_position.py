"""
Given a sorted array of distinct integers and
a target value, return the index if the target
is found. If not, return the index where it would
be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
"""

def searchInsert(self, nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    left = 0
    right = len(nums) - 1
    res = len(nums)
    while left <= right:
      mid = (left + right) >> 1
      if nums[mid] < target:
        left = mid + 1
      else:
        right = mid - 1
        res = mid
    return res
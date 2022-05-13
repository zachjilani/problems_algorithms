"""
Given a non-empty array of integers nums, every
element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity
and use only constant extra space.
"""

def singleNumber(self, nums):
  """
  :type nums: List[int]
  :rtype: int
  """
  x = 0
  for n in nums:
      x ^= n
  return x
"""
Given an integer array nums, in which exactly two
elements appear only once and all the other elements
appear exactly twice. Find the two elements that appear
only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime
complexity and uses only constant extra space.
"""

def singleNumber(self, nums):
  """
  :type nums: List[int]
  :rtype: List[int]
  """

  nums.sort()
  evens = []
  odds = []

  for i in range(0, len(nums)):
    if i%2 == 0:
      evens.append(nums[i])
    else:
      odds.append(nums[i])
  return list(set(evens) - set(odds)) + list(set(odds) - set(evens))
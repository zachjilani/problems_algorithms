"""
Given an array nums of distinct integers, return
all the possible permutations. You can return the answer in any order.
"""

def permute(self, nums):
  """
  :type nums: List[int]
  :rtype: List[List[int]]
  """
  res = []
  l = list(itertools.permutations(nums))
  for i in l:
    res.append(i)
  return res
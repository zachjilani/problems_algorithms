"""
Given two integers n and k, return all possible
combinations of k numbers out of the range [1, n].

You may return the answer in any order.
"""

import itertools
def combine(self, n, k):
  """
  :type n: int
  :type k: int
  :rtype: List[List[int]]
  """
  nlist = []
  for i in range(1, n + 1):
    nlist.append(i)
  return list(itertools.combinations(nlist, k))
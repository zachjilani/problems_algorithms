"""
Given an integer n, return true if it is a power of three.
Otherwise, return false.

An integer n is a power of three, if there exists an
integer x such that n == 3x
"""

def isPowerOfThree(self, n):
    """
    :type n: int
    :rtype: bool
    """
    if not n:
      return False
    if n == 3 or n == 1:
      return True
    if n!= 3 and n % 3 == 0:
      n = n/3
      return self.isPowerOfThree(n)
    return False
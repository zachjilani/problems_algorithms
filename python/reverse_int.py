"""
Given a signed 32-bit integer x, return x with its digits reversed.
 If reversing x causes the value to go outside the signed 32-bit
 integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
"""

def reverse(self, x):
  """
  :type x: int
  :rtype: int
  """
  sign = self.sign(x)
  maxnum = (2**31) - 1
  minnum = (-2**31)
  if x > 9 and x <= -9:
    return x
  if x == maxnum or x == minnum:
    return 0
  x = abs(x)
  result = 0
  while(x > 0):
    digit = x%10
    if result > maxnum/10 or (result == maxnum/10 and digit > maxnum%10):
        return 0
    result = result * 10 + digit
    x /= 10
  return result*sign

def sign(self, number):
  return 1 if (number > 0) else -1
"""
Given an integer num, repeatedly add all its digits
until the result has only one digit, and return it.
"""

def addDigits(self, num):
  """
  :type num: int
  :rtype: int
  """
  if num < 10:
    return num
  return self.addDigits(((num%10)+(num/10)))



def isValid(s):
  stack = []
  d = {'(': ')', '{': '}', '[': ']'}
  for c in s:
    if c in '({[':
      stack.append(c)
    else:
      if not stack or c != d[stack.pop()]:
        return False
  return len(stack) == 0

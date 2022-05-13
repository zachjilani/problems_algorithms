


def fizzbuzz(n):
  if n > 10**4 or n < 1:
    return "fuck you buddy"

  l = []
  for i in range(1, n + 1):
    if i % 3 == 0 and i % 5 == 0:
      l.append("FizzBuzz")
    elif i % 3 == 0:
      l.append("Fizz")
    elif i % 5 == 0:
      l.append("Buzz")
    else:
      l.append(str(i))
  return l



print(fizzbuzz(15))

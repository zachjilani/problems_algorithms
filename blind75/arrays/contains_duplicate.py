

def contains_duplicate(nums):
  if len(set(nums)) == len(nums):
    return False
  else:
    return True

nums = [1,2,3,1]

print(contains_duplicate(nums))
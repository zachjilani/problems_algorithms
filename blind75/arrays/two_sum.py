

def two_sum(nums, target):

  d = {}
  for i in range(len(nums)):
    if (target - nums[i]) not in d:
      d[nums[i]] = i
    else:
      return [d[target - nums[i]], i]
  return [-1,-1]

nums = [2,7,11,15]
target = 9

print(two_sum(nums, target))
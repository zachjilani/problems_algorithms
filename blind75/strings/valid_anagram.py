def isAnagram(self, s, t):
  """
  :type s: str
  :type t: str
  :rtype: bool
  """
  s_dict, t_dict = dict(), dict()
  for letter in s:
    if letter not in s_dict:
      s_dict[letter] = 1
    else:
      s_dict[letter] = s_dict[letter] + 1
  for letter in t:
    if letter not in t_dict:
      t_dict[letter] = 1
    else:
      t_dict[letter] = t_dict[letter] + 1

  if s_dict == t_dict:
    return True
  return False
"""
Given the root of a binary tree, invert the tree, and return its root.

Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

def invertTree(self, root):
  """
  :type root: TreeNode
  :rtype: TreeNode
  """
  if root == None:
    return root
  tmp = root.left
  root.left = root.right
  root.right = tmp

  left = self.invertTree(root.left)
  right = self.invertTree(root.right)

  return root
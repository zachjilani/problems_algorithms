"""
Given the head of a sorted linked list, delete
all duplicates such that each element appears
only once. Return the linked list sorted as well.

Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
"""

def deleteDuplicates(self, head):
  """
  :type head: ListNode
  :rtype: ListNode
  """
  result = head

  while head and head.next:
    if head.val == head.next.val:
      head.next = head.next.next
    else:
      head = head.next

  return result
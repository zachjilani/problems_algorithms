# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
def reverseList(self, head):

  """
  :type head: ListNode
  :rtype: ListNode
  """
  if head is None or head.next is None:
    return head
  prev = head
  curr = prev.next
  nex = curr.next
  prev.next = None

  if nex == None:
    curr.next = prev
    prev.next = None
    return curr

  while nex.next:
    curr.next = prev
    prev = curr
    curr = nex
    nex = nex.next
  nex.next = curr
  curr.next = prev

  return nex

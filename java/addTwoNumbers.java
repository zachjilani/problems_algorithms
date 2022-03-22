

// You are given two non-empty linked lists representing two
// non-negative integers. The digits are stored in reverse order,
// and each of their nodes contains a single digit. Add the two
// numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading
// zero, except the number 0 itself.
// EXAMPLES:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Input: l1 = [0], l2 = [0]
// Output: [0]


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

public class addTwoNumbers {

  public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode res = new ListNode();
    ListNode temp = res;
    int carry = 0;
    int sum;
    while(l1 != null || l2 != null || carry == 1){
        sum = carry;
        if(l1 != null){
            sum = sum + l1.val;
            l1 = l1.next;
        }
        if(l2 != null){
            sum = sum + l2.val;
            l2 = l2.next;
        }
        if(sum > 9){
            carry = 1;
            sum = sum % 10;
        }else{
            carry = 0;
        }
        temp.next = new ListNode(sum);
        temp = temp.next;
    }
    return res.next;
  }
}

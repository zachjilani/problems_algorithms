



// Given the head of a linked list and an integer val,
// remove all the nodes of the linked list that has
// Node.val == val, and return the new head.
// due to being provided a defined ListNode class,
// there is no main.
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
public class removeLlistElement {
  public ListNode removeElements(ListNode head, int val) {
    ListNode temp = new ListNode(0);
    ListNode result = temp;
    while(head != null){
        if(head.val != val){
            temp.next = head;
            temp = temp.next;
        }
        head = head.next;
    }
    temp.next = null;
    return result.next;
  }
}

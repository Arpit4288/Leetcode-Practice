/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {

    public ListNode Reverse(ListNode curr, ListNode prev){
        if(curr == null) return prev;
        ListNode temp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = temp;
        return Reverse(curr, prev);
    }

    public ListNode ReverseList(ListNode head) {
        if(head == null || head.next == null) return head;

        ListNode prev = null;
        return Reverse(head, prev);
    }
}
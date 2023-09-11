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
    public ListNode ReverseBetween(ListNode head, int left, int right) {
        var dummy = new ListNode();
        dummy.next = head;
        var current = dummy;
        for (var i = 0; i < left - 1; i++)
        {
            current = current.next;
        }
        
        var prev = current;
        var node = current.next;
        for (var i = left; i <= right; i++)
        {
            var next = node.next;
            node.next = prev;
            prev = node;
            node = next;
        }
        
        current.next.next = node;
        current.next = prev;
        return dummy.next;
    }
}
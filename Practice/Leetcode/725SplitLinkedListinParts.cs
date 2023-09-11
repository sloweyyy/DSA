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
public class Solution
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode[] SplitListToParts(ListNode head, int k)
    {
        var result = new ListNode[k];
        var length = 0;
        var current = head;
        while (current != null)
        {
            length++;
            current = current.next;
        }

        var size = length / k;
        var remainder = length % k;
        current = head;
        for (var i = 0; i < k; i++)
        {
            var count = size + (remainder > 0 ? 1 : 0);
            remainder--;
            var dummy = new ListNode();
            var node = dummy;
            for (var j = 0; j < count; j++)
            {
                node.next = new ListNode(current.val);
                node = node.next;
                current = current.next;
            }

            result[i] = dummy.next;
        }

        return result;
    }
}
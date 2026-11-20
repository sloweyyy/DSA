class Solution {
    ListNode? removeElements(ListNode? head, int val) {
        final dummy = ListNode(0, head);
        var previous = dummy;
        while (previous.next != null) {
            if (previous.next!.val == val) {
                previous.next = previous.next!.next;
            }
            else {
                previous = previous.next!;
            }
        }
        return dummy.next;
    }
}

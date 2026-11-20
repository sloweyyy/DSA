class Solution {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        val a = mutableListOf<Int>();
        val b = mutableListOf<Int>();
        var p = l1;
        while (p != null) {
            a.add(p.`val`);
            p = p.next;
        };
        p = l2;
        while (p != null) {
            b.add(p.`val`);
            p = p.next;
        };
        var carry = 0;
        var head: ListNode? = null;
        while (a.isNotEmpty() || b.isNotEmpty() || carry != 0) {
            var sum = carry;
            if (a.isNotEmpty()) sum += a.removeAt(a.lastIndex);
            if (b.isNotEmpty()) sum += b.removeAt(b.lastIndex);
            val node = ListNode(sum % 10);
            node.next = head;
            head = node;
            carry = sum / 10;
        };
        return head;
    }
}

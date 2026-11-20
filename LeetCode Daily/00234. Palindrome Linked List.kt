class Solution {
    private fun reverse(head: ListNode?): ListNode? {
        var current = head;
        var previous: ListNode? = null;
        while (current != null) {
            val next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        };
        return previous;
    }
    fun isPalindrome(head: ListNode?): Boolean {
        if (head?.next == null) return true;
        var slow = head;
        var fast = head;
        while (fast?.next?.next != null) {
            slow = slow!!.next;
            fast = fast!!.next!!.next;
        };
        val middle = slow!!;
        val second = reverse(middle.next);
        var left = head;
        var right = second;
        var result = true;
        while (right != null) {
            if (left!!.`val` != right.`val`) {
                result = false;
                break;
            };
            left = left!!.next;
            right = right.next;
        };
        middle.next = reverse(second);
        return result;
    }
}

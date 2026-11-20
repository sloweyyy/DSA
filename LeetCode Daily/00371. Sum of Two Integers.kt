class Solution {
    fun getSum(a: Int, b: Int): Int {
        var first = a;
        var second = b;
        while (second != 0) {
            val carry = (first and second) shl 1;
            first = first xor second;
            second = carry;
        };
        return first;
    }
}

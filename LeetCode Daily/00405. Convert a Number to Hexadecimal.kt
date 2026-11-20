class Solution {
    fun toHex(num: Int): String {
        if (num == 0) return "0";
        val digits = "0123456789abcdef";
        val result = StringBuilder();
        var value = num;
        while (value != 0) {
            result.append(digits[value and 15]);
            value = value ushr 4;
        };
        return result.reverse().toString();
    }
}

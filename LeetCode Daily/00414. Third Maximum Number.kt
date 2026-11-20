class Solution {
    fun thirdMax(nums: IntArray): Int {
        var first = Long.MIN_VALUE;
        var second = Long.MIN_VALUE;
        var third = Long.MIN_VALUE;
        for (number in nums) {
            val value = number.toLong();
            if (value == first || value == second || value == third) continue;
            if (value > first) {
                third = second;
                second = first;
                first = value;
            }
            else if (value > second) {
                third = second;
                second = value;
            }
            else if (value > third) third = value;
        };
        return (if (third == Long.MIN_VALUE) first else third).toInt();
    }
}

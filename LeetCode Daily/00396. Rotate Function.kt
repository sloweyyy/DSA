class Solution {
    fun maxRotateFunction(nums: IntArray): Int {
        var sum = 0L;
        var current = 0L;
        for (index in nums.indices) {
            sum += nums[index];
            current += index.toLong() * nums[index];
        };
        var best = current;
        for (index in nums.size - 1 downTo 1) {
            current += sum - nums.size.toLong() * nums[index];
            best = maxOf(best, current);
        };
        return best.toInt();
    }
}

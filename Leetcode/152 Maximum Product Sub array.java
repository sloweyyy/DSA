class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        int[] dp2 = new int[n];
        dp[0] = nums[0];
        dp2[0] = nums[0];
        int max = nums[0];

        for(int i = 1; i < n; i++) {
            dp[i] = Math.max(nums[i], Math.max(dp[i - 1] * nums[i], dp2[i - 1] * nums[i]));
            dp2[i] = Math.min(nums[i], Math.min(dp[i - 1] * nums[i], dp2[i - 1] * nums[i]));
            max = Math.max(max, dp[i]);
        }

        return max;
    }
}
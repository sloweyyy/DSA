class Solution {
    public int numOfWays(int n) {
        int MOD = (int) Math.pow(10, 9) + 7;
        int[][] dp = new int[n][2];
        dp[0][0] = 6;
        dp[0][1] = 6;
        for (int i = 1; i < n; i++) {
            dp[i][0] = (int) ((dp[i-1][0] * 3L + dp[i-1][1] * 2L) % MOD);
            dp[i][1] = (int) ((dp[i-1][0] * 2L + dp[i-1][1] * 2L) % MOD);
        }
        return (dp[n-1][0] + dp[n-1][1]) % MOD;
    }
}
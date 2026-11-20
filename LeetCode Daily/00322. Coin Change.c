int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = malloc((amount + 1) * sizeof(int));
    dp[0] = 0;
    for (int sum = 1; sum <= amount; sum++) {
        dp[sum] = amount + 1;
        for (int i = 0; i < coinsSize; i++) {
            if (coins[i] <= sum && dp[sum - coins[i]] + 1 < dp[sum]) dp[sum] = dp[sum - coins[i]] + 1;
        }
    }
    int answer = dp[amount] > amount ? -1 : dp[amount];
    free(dp);
    return answer;
}

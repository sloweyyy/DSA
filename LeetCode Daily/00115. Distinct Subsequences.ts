function numDistinct(s: string, t: string): number {
    const dp: number[] = Array(t.length + 1).fill(0);
    dp[0] = 1;
    for (let i = 0; i < s.length; i++) {
        for (let j = Math.min(t.length, i + 1); j >= 1; j--) {
            if (s[i] === t[j - 1]) dp[j] = Math.min(2147483647, dp[j] + dp[j - 1]);
        }
    }
    return dp[t.length];
}

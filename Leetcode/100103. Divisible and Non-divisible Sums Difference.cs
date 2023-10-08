public class Solution
{
    public int DifferenceOfSums(int k, int n)
    {
        const int mod = 1000000007;

        int[][] dp = new int[n + 1][];
        int[][] prefix = new int[n + 1][];
        int[][] prevDp = new int[n + 1][];
        int[][] prevPrefix = new int[n + 1][];

        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[2];
            prefix[i] = new int[2];
            prevDp[i] = new int[2];
            prevPrefix[i] = new int[2];
        }

        for (int j = 1; j <= n; j++)
        {
            prevDp[j][0] = dp[j][0] = 1;
            prevPrefix[j][0] = prefix[j][0] = j;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int maxNum = 1; maxNum <= n; maxNum++)
            {
                dp[maxNum][0] = (int)(((long)maxNum * prevDp[maxNum][0]) % mod);

                if (maxNum % k != 0)
                {
                    dp[maxNum][1] = (int)(((long)(maxNum % k) * prevDp[maxNum][1]) % mod);

                    if (maxNum > 1)
                    {
                        dp[maxNum][1] = (dp[maxNum][1] + prevPrefix[maxNum - 1][1]) % mod;
                    }
                }

                prefix[maxNum][0] = (prefix[maxNum - 1][0] + dp[maxNum][0]) % mod;
                prefix[maxNum][1] = (prefix[maxNum - 1][1] + dp[maxNum][1]) % mod;
            }

            for (int j = 1; j <= n; j++)
            {
                Array.Copy(dp[j], prevDp[j], 2);
                Array.Copy(prefix[j], prevPrefix[j], 2);
            }
        }

        return (prefix[n][0] - prefix[n][1] + mod) % mod;
    }
}

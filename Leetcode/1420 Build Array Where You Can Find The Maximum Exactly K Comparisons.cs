public class Solution
{
    public int NumOfArrays(int n, int m, int k)
    {
        int mod = 1000000007;
        int[,,] dp = new int[n + 1, m + 1, k + 1];
        for (int i = 1; i <= m; i++)
            dp[1, i, 1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int l = 1; l <= k; l++)
                {
                    dp[i, j, l] = (dp[i, j, l] + dp[i - 1, j, l] * j) % mod;
                    for (int p = 1; p < j; p++)
                        dp[i, j, l] = (dp[i, j, l] + dp[i - 1, p, l - 1]) % mod;
                }
            }
        }
        int result = 0;
        for (int i = 1; i <= m; i++)
            result = (result + dp[n, i, k]) % mod;
        return result;
    }
}
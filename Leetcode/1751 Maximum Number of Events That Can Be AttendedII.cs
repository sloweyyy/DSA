public class Solution
{
    public int MaxValue(int[][] events, int k)
    {
        int n = events.Length;
        int[][] dp = new int[n + 1][];
        for (int i = 0; i < dp.Length; i++)
        {
            dp[i] = new int[k + 1];
        }
        Array.Sort(events, (a, b) => a[1] - b[1]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int l = 0;
                int r = i - 1;
                while (l < r)
                {
                    int mid = l + (r - l) / 2;
                    if (events[mid][1] < events[i - 1][0])
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid;
                    }
                }
                dp[i][j] = Math.Max(dp[i - 1][j], dp[l][j - 1] + events[i - 1][2]);
            }
        }
        return dp[n][k];
    }
}
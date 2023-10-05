public class Solution
{
    public int MinTaps(int n, int[] ranges)
    {
        int[] dp = new int[n + 1];
        for (int i = 0; i < ranges.Length; i++)
        {
            int left = Math.Max(0, i - ranges[i]);
            int right = Math.Min(n, i + ranges[i]);
            dp[left] = Math.Max(dp[left], right);
        }
        int count = 0;
        int end = 0;
        int farthest = 0;
        for (int i = 0; i < dp.Length - 1; i++)
        {
            farthest = Math.Max(farthest, dp[i]);
            if (i == end)
            {
                count++;
                end = farthest;
            }
        }
        return end >= n ? count : -1;
    }
}
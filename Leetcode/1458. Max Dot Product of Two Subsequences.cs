public class Solution
{
    public int MaxDotProduct(int[] nums1, int[] nums2)
    {
        int n = nums1.Length;
        int m = nums2.Length;
        int[,] dp = new int[n, m];

        dp[0, 0] = nums1[0] * nums2[0];

        for (int i = 1; i < n; i++)
        {
            dp[i, 0] = Math.Max(dp[i - 1, 0], nums1[i] * nums2[0]);
        }

        for (int j = 1; j < m; j++)
        {
            dp[0, j] = Math.Max(dp[0, j - 1], nums1[0] * nums2[j]);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i, j] = Math.Max(
                    nums1[i] * nums2[j] + Math.Max(dp[i - 1, j - 1], 0),
                    Math.Max(dp[i - 1, j], dp[i, j - 1])
                );
            }
        }

        return dp[n - 1, m - 1];
    }
}
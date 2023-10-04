public class Solution
{
    public int MinCost(int n, int[] cuts)
    {
        Array.Sort(cuts);
        int[] newCuts = new int[cuts.Length + 2];
        newCuts[0] = 0;
        newCuts[newCuts.Length - 1] = n;
        for (int i = 0; i < cuts.Length; i++)
        {
            newCuts[i + 1] = cuts[i];
        }
        int[,] dp = new int[newCuts.Length, newCuts.Length];
        for (int i = newCuts.Length - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < newCuts.Length; j++)
            {
                if (j - i == 1)
                {
                    dp[i, j] = 0;
                }
                else
                {
                    dp[i, j] = int.MaxValue;
                    for (int k = i + 1; k < j; k++)
                    {
                        dp[i, j] = Math.Min(dp[i, j], dp[i, k] + dp[k, j] + newCuts[j] - newCuts[i]);
                    }
                }
            }
        }
        return dp[0, newCuts.Length - 1];
    }
}
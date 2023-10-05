public class Solution
{
    public int DiagonalSum(int[][] mat)
    {
        int sum = 0;
        int n = mat.Length;
        for (int i = 0; i < n; i++)
        {
            sum += mat[i][i];
            sum += mat[i][n - i - 1];
        }
        if (n % 2 == 1)
        {
            sum -= mat[n / 2][n / 2];
        }
        return sum;
    }
}
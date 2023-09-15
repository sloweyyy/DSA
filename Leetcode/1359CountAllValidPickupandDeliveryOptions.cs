public class Solution
{
    public int CountOrders(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        long result = 1;
        for (int i = 2; i <= n; i++)
        {
            result = result * (2 * i - 1) * i;
            result = result % 1000000007;
        }
        return (int)result;
    }
}
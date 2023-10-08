public class Solution
{
    public int[] GetNoZeroIntegers(int n)
    {
        for (int i = 1; i < n; i++)
        {
            if (i.ToString().Contains("0"))
            {
                continue;
            }
            if ((n - i).ToString().Contains("0"))
            {
                continue;
            }
            return new int[] { i, n - i };
        }
        return new int[] { };
    }
}
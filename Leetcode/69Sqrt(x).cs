public class Solution
{
    public int MySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        int left = 1;
        int right = x;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid && (mid + 1) > x / (mid + 1))
            {
                return mid;
            }
            else if (mid > x / mid)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
}
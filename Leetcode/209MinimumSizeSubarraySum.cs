public class Solution
{
    public int MinSubArrayLen(int target, int[] nums)
    {
        int sum = 0;
        int left = 0;
        int min = int.MaxValue;
        for (int i = 0; i < nums.Length; i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                min = Math.Min(min, i - left + 1);
                sum -= nums[left++];
            }
        }
        return min == int.MaxValue ? 0 : min;
    }
}
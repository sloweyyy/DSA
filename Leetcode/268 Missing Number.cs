using System;
public class Solution
{
    public int MissingNumber(int[] nums)
    {
        int result = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            result ^= nums[i];
            result ^= i;
        }
        result ^= nums.Length;
        return result;
    }

    static void Main(string[] args)
    {
        Solution sol = new Solution();
        int[] nums = new int[] { 3, 0, 1 };
        Console.WriteLine(sol.MissingNumber(nums));
        
    }
}


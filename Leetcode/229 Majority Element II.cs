public class Solution
{
    public IList<int> MajorityElement(int[] nums)
    {
        var result = new List<int>();
        if (nums.Length == 0)
            return result;

        var candidate1 = nums[0];
        var candidate2 = nums[0];
        var count1 = 0;
        var count2 = 0;

        foreach (var num in nums)
        {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
            else if (count1 == 0)
            {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = num;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        foreach (var num in nums)
        {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }

        if (count1 > nums.Length / 3)
            result.Add(candidate1);
        if (count2 > nums.Length / 3)
            result.Add(candidate2);

        return result;
    }
}
public class Solution
{
    public bool Find132pattern(int[] nums)
    {
        if (nums.Length < 3)
            return false;

        var min = new int[nums.Length];
        min[0] = nums[0];
        for (var i = 1; i < nums.Length; i++)
            min[i] = Math.Min(min[i - 1], nums[i]);

        var stack = new Stack<int>();
        for (var i = nums.Length - 1; i >= 0; i--)
        {
            if (nums[i] > min[i])
            {
                while (stack.Count > 0 && stack.Peek() <= min[i])
                    stack.Pop();

                if (stack.Count > 0 && stack.Peek() < nums[i])
                    return true;

                stack.Push(nums[i]);
            }
        }

        return false;
    }
}
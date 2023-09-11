public class Solution
{
    public int[] MaxSlidingWindow(int[] nums, int k)
    {
        var result = new List<int>();
        var queue = new Queue<int>();
        for (var i = 0; i < nums.Length; i++)
        {
            if (queue.Count > 0 && queue.Peek() == i - k)
            {
                queue.Dequeue();
            }

            while (queue.Count > 0 && nums[queue.Peek()] < nums[i])
            {
                queue.Dequeue();
            }

            queue.Enqueue(i);
            if (i >= k - 1)
            {
                result.Add(nums[queue.Peek()]);
            }
        }

        return result.ToArray();

    }
}
using System.Collections.Generic;
using System.Linq;

public class KthLargest
{
    private int k;
    private List<int> nums;

    public KthLargest(int k, int[] nums)
    {
        this.k = k;
        this.nums = nums.ToList();
    }

    public int Add(int val)
    {
        nums.Add(val);
        nums.Sort();
        return nums[nums.Count - k];
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.Add(val);
 */
public class Solution {
    public int[] SortArrayByParity(int[] nums) {
        int[] result = new int[nums.Length];
        int evenIndex = 0;
        int oddIndex = nums.Length - 1;
        foreach (int num in nums) {
            if (num % 2 == 0) {
                result[evenIndex++] = num;
            } else {
                result[oddIndex--] = num;
            }
        }
        return result;
    }
}
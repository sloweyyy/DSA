public class Solution {
    public IList<int> CountSmaller(int[] nums) {
        int[] tree = new int[20002];
        int[] result = new int[nums.Length];
        for (int i = nums.Length - 1; i >= 0; i--) {
            int rank = nums[i] + 10001;
            int count = 0;
            for (int index = rank - 1; index > 0; index -= index & -index) count += tree[index];
            result[i] = count;
            for (int index = rank; index < tree.Length; index += index & -index) tree[index]++;
        }
        return result;
    }
}

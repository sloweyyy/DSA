class Solution {
    TreeNode? sortedArrayToBST(List<int> nums) {
        TreeNode? build(int left, int right) {
            if (left > right) return null;
            final middle = left + ((right - left) ~/ 2);
            return TreeNode(nums[middle], build(left, middle - 1), build(middle + 1, right));
        }
        return build(0, nums.length - 1);
    }
}

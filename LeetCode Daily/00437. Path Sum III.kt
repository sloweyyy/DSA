class Solution {
    fun pathSum(root: TreeNode?, targetSum: Int): Int {
        val counts = hashMapOf<Long, Int>(0L to 1);
        fun dfs(node: TreeNode?, prefix: Long): Int {
            if (node == null) return 0;
            val sum = prefix + node.`val`.toLong();
            var total = counts.getOrDefault(sum - targetSum.toLong(), 0);
            counts[sum] = counts.getOrDefault(sum, 0) + 1;
            total += dfs(node.left, sum) + dfs(node.right, sum);
            counts[sum] = counts[sum]!! - 1;
            return total;
        };
        return dfs(root, 0L);
    }
}

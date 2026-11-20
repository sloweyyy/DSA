class Solution {
    List<int> rightSideView(TreeNode? root) {
        final result = <int>[];
        void visit(TreeNode? node, int depth) {
            if (node == null) return;
            if (depth == result.length) result.add(node.val);
            visit(node.right, depth + 1);
            visit(node.left, depth + 1);
        }
        visit(root, 0);
        return result;
    }
}

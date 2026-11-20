class Solution {
    bool isValidBST(TreeNode? root) {
        final stack = <TreeNode>[];
        TreeNode? node = root;
        int? previous;
        while (node != null || stack.isNotEmpty) {
            while (node != null) {
                stack.add(node);
                node = node.left;
            }
            final current = stack.removeLast();
            if (previous != null && current.val <= previous) return false;
            previous = current.val;
            node = current.right;
        }
        return true;
    }
}

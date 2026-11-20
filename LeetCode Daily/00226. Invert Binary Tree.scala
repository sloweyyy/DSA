object Solution {
    def invertTree(root: TreeNode): TreeNode = {
        if (root != null) {
            val left = invertTree(root.left);
            root.left = invertTree(root.right);
            root.right = left;
        };
        root
    }
}

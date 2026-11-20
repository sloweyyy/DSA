object Solution {
    def lowestCommonAncestor(root: TreeNode, p: TreeNode, q: TreeNode): TreeNode = {
        val parents = scala.collection.mutable.Map[TreeNode, TreeNode](root -> null);
        val stack = scala.collection.mutable.Stack[TreeNode](root);
        while (!parents.contains(p) || !parents.contains(q)) {
            val node = stack.pop();
            if (node.left != null) {
                parents(node.left) = node;
                stack.push(node.left);
            };
            if (node.right != null) {
                parents(node.right) = node;
                stack.push(node.right);
            }
        };
        val ancestors = scala.collection.mutable.HashSet.empty[TreeNode];
        var current = p;
        while (current != null) {
            ancestors.add(current);
            current = parents(current);
        };
        current = q;
        while (!ancestors.contains(current)) {
            current = parents(current);
        };
        current
    }
}

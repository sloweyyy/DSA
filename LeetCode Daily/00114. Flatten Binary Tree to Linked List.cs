public class Solution {
    public void Flatten(TreeNode root) {
        TreeNode current = root;
        while (current != null) {
            if (current.left != null) {
                TreeNode predecessor = current.left;
                while (predecessor.right != null) predecessor = predecessor.right;
                predecessor.right = current.right;
                current.right = current.left;
                current.left = null;
            }
            current = current.right;
        }
    }
}

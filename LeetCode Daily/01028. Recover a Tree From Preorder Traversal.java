
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    public TreeNode recoverFromPreorder(String traversal) {
        Stack<TreeNode> stack = new Stack<>();
        int i = 0;
        while (i < traversal.length()) {
            int level = 0;
            while (i < traversal.length() && traversal.charAt(i) == '-') {
                level++;
                i++;
            }

            int value = 0;
            while (i < traversal.length() && traversal.charAt(i) >= '0' && traversal.charAt(i) <= '9') {
                value = value * 10 + (traversal.charAt(i) - '0');
                i++;
            }

            TreeNode node = new TreeNode(value);
            while (stack.size() > level) {
                stack.pop();
            }

            if (!stack.isEmpty()) {
                if (stack.peek().left == null) {
                    stack.peek().left = node;
                } else {
                    stack.peek().right = node;
                }
            }
            stack.push(node);
        }

        return stack.isEmpty() ? null : stack.firstElement();
    }
}

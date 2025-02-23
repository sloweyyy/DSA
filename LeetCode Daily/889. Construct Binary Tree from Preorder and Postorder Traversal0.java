
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

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        return buildTree(preorder, postorder, 0, preorder.length - 1, 0, postorder.length - 1);
    }

    private TreeNode buildTree(int[] preorder, int[] postorder, int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[preStart]);

        if (preStart == preEnd) {
            return root;
        }

        int leftRoot = preorder[preStart + 1];
        int leftRootIndex = -1;
        for (int i = postStart; i <= postEnd; i++) {
            if (postorder[i] == leftRoot) {
                leftRootIndex = i;
                break;
            }
        }

        int leftLength = leftRootIndex - postStart + 1;

        root.left = buildTree(preorder, postorder, preStart + 1, preStart + leftLength, postStart, leftRootIndex);
        root.right = buildTree(preorder, postorder, preStart + leftLength + 1, preEnd, leftRootIndex + 1, postEnd - 1);

        return root;
    }
}

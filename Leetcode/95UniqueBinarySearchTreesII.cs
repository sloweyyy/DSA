/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    public IList<TreeNode> GenerateTrees(int n)
    {
        if (n == 0)
        {
            return new List<TreeNode>();
        }
        return generateTrees(1, n);
    }
    private IList<TreeNode> generateTrees(int start, int end)
    {
        IList<TreeNode> res = new List<TreeNode>();
        if (start > end)
        {
            res.Add(null);
            return res;
        }
        for (int i = start; i <= end; i++)
        {
            IList<TreeNode> left = generateTrees(start, i - 1);
            IList<TreeNode> right = generateTrees(i + 1, end);
            foreach (TreeNode l in left)
            {
                foreach (TreeNode r in right)
                {
                    TreeNode root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    res.Add(root);
                }
            }
        }
        return res;
    }
}
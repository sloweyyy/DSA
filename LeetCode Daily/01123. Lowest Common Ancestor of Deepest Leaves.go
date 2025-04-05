/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	leftDepth := getDepth(root.Left)
	rightDepth := getDepth(root.Right)

	if leftDepth == rightDepth {
		return root
	}

	if leftDepth > rightDepth {
		return lcaDeepestLeaves(root.Left)
	}

	return lcaDeepestLeaves(root.Right)
}

func getDepth(node *TreeNode) int {
	if node == nil {
		return 0
	}
	leftDepth := getDepth(node.Left)
	rightDepth := getDepth(node.Right)
	if leftDepth > rightDepth {
		return leftDepth + 1
	}
	return rightDepth + 1
}

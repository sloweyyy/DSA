type BSTIterator struct{ stack []*TreeNode }

func Constructor(root *TreeNode) BSTIterator {
	iterator := BSTIterator{}
	iterator.pushLeft(root)
	return iterator
}
func (iterator *BSTIterator) pushLeft(node *TreeNode) {
	for node != nil {
		iterator.stack = append(iterator.stack, node)
		node = node.Left
	}
}
func (iterator *BSTIterator) Next() int {
	last := len(iterator.stack) - 1
	node := iterator.stack[last]
	iterator.stack = iterator.stack[:last]
	iterator.pushLeft(node.Right)
	return node.Val
}
func (iterator *BSTIterator) HasNext() bool { return len(iterator.stack) > 0 }

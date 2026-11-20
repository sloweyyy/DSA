class Solution(object):
    def buildTree(self, inorder, postorder):
        root = TreeNode(postorder[-1])
        stack = [root]
        index = len(inorder) - 1
        for value in reversed(postorder[:-1]):
            parent = stack[-1]
            node = TreeNode(value)
            if parent.val != inorder[index]:
                parent.right = node
            else:
                while stack and stack[-1].val == inorder[index]:
                    parent = stack.pop()
                    index -= 1
                parent.left = node
            stack.append(node)
        return root

var buildTree = function(preorder, inorder) {
    if (preorder.length === 0) return null;
    const root = new TreeNode(preorder[0]);
    const stack = [root];
    let index = 0;
    for (let i = 1; i < preorder.length; i++) {
        let parent = stack[stack.length - 1];
        const node = new TreeNode(preorder[i]);
        if (parent.val !== inorder[index]) {
            parent.left = node;
        }
        else {
            while (stack.length && stack[stack.length - 1].val === inorder[index]) {
                parent = stack.pop();
                index++;
            }
            parent.right = node;
        }
        stack.push(node);
    }
    return root;
};

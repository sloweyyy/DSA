function countNodes(root: TreeNode | null): number {
    if (root === null) return 0;
    let left: TreeNode | null = root;
    let right: TreeNode | null = root;
    let leftHeight = 0, rightHeight = 0;
    while (left !== null) {
        leftHeight++;
        left = left.left;
    }
    while (right !== null) {
        rightHeight++;
        right = right.right;
    }
    if (leftHeight === rightHeight) return 2 ** leftHeight - 1;
    return 1 + countNodes(root.left) + countNodes(root.right);
}

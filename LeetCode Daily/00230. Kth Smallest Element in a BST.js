var kthSmallest = function(root, k) {
    const stack = [];
    let node = root;
    while (node !== null || stack.length > 0) {
        while (node !== null) {
            stack.push(node);
            node = node.left;
        }
        node = stack.pop();
        if (--k === 0) return node.val;
        node = node.right;
    }
    return -1;
};

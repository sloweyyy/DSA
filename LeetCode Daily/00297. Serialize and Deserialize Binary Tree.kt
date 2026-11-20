class Codec {
    fun serialize(root: TreeNode?): String {
        if (root == null) return "#";
        val queue = ArrayList<TreeNode?>();
        queue.add(root);
        val output = StringBuilder();
        var index = 0;
        while (index < queue.size) {
            val node = queue[index++];
            if (node == null) output.append("#,") else {
                output.append(node.`val`).append(',');
                queue.add(node.left);
                queue.add(node.right);
            }
        };
        return output.toString();
    }
    fun deserialize(data: String): TreeNode? {
        if (data == "#") return null;
        val tokens = data.split(',');
        val root = TreeNode(tokens[0].toInt());
        val queue = ArrayList<TreeNode>();
        queue.add(root);
        var head = 0;
        var index = 1;
        while (head < queue.size) {
            val node = queue[head++];
            val left = tokens[index++];
            if (left != "#") {
                node.left = TreeNode(left.toInt());
                queue.add(node.left!!);
            };
            val right = tokens[index++];
            if (right != "#") {
                node.right = TreeNode(right.toInt());
                queue.add(node.right!!);
            }
        };
        return root;
    }
}

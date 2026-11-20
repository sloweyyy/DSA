public class Solution {
    public Node Connect(Node root) {
        Node level = root;
        while (level != null && level.left != null) {
            for (Node current = level; current != null; current = current.next) {
                current.left.next = current.right;
                current.right.next = current.next == null ? null : current.next.left;
            }
            level = level.left;
        }
        return root;
    }
}

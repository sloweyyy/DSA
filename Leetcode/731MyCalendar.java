class MyCalendarTwo {
    Node root;
    public MyCalendarTwo() {
    }
    public boolean book(int start, int end) {
        if (!insertable(start, end, root)) {
            return false;
        }
        root = insert(start, end, root);
        return true;
    }
    private Node insert(int start, int end, Node cur) {
        if (start >= end) return cur;
        if (cur == null) return new Node(start, end);
        if (start >= cur.end) {
            cur.right = insert(start, end, cur.right);
            return cur;
        } else if (end <= cur.start) {
            cur.left = insert(start, end, cur.left);
            return cur;
        } else {
            cur.overlap = true;
            int a = Math.min(cur.start, start);
            int b = Math.max(cur.start, start);
            int c = Math.min(cur.end, end);
            int d = Math.max(cur.end, end);
            cur.left = insert(a, b, cur.left);
            cur.right = insert(c, d, cur.right);
            cur.start = b;
            cur.end = c;
            return cur;
        }
    }
    private boolean insertable(int start, int end, Node cur) {
        if (start >= end) return true;
        if (cur == null) return true;
        if (start >= cur.end) {
            return insertable(start, end, cur.right);
        } else if (end <= cur.start) {
            return insertable(start, end, cur.left);
        } else {
            if (cur.overlap) {
                return false;
            } else {
                if (start >= cur.start && end <= cur.end) {
                    return true;
                } else {
                    return insertable(start, cur.start, cur.left) && insertable(cur.end, end, cur.right);
                }
            }
        }
    }
    class Node {
        int start, end;
        boolean overlap;
        Node left, right;
        Node(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
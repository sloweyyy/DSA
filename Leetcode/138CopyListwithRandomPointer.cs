/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    
    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution
{
    public Node CopyRandomList(Node head)
    {
        if (head == null)
        {
            return null;
        }

        var node = head;
        while (node != null)
        {
            var newNode = new Node(node.val);
            newNode.next = node.next;
            node.next = newNode;
            node = newNode.next;
        }

        node = head;
        while (node != null)
        {
            if (node.random != null)
            {
                node.next.random = node.random.next;
            }

            node = node.next.next;
        }

        node = head;
        var newHead = head.next;
        while (node != null)
        {
            var temp = node.next;
            node.next = temp.next;
            if (temp.next != null)
            {
                temp.next = temp.next.next;
            }

            node = node.next;
        }

        return newHead;
    }
}
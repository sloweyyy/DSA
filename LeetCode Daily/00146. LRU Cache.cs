public class LRUCache {
    private readonly int capacity;
    private readonly Dictionary<int, LinkedListNode<(int Key, int Value)>> nodes = new Dictionary<int, LinkedListNode<(int Key, int Value)>>();
    private readonly LinkedList<(int Key, int Value)> order = new LinkedList<(int Key, int Value)>();
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    public int Get(int key) {
        if (!nodes.TryGetValue(key, out var node)) return -1;
        order.Remove(node);
        order.AddFirst(node);
        return node.Value.Value;
    }
    public void Put(int key, int value) {
        if (nodes.TryGetValue(key, out var node)) {
            node.Value = (key, value);
            order.Remove(node);
            order.AddFirst(node);
            return;
        }
        nodes[key] = order.AddFirst((key, value));
        if (nodes.Count > capacity) {
            var last = order.Last;
            order.RemoveLast();
            nodes.Remove(last.Value.Key);
        }
    }
}

class Solution {
    public: Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> copies;
        queue<Node*> pending;
        copies[node] = new Node(node->val);
        pending.push(node);
        while (!pending.empty()) {
            Node* current = pending.front();
            pending.pop();
            for (Node* neighbor : current->neighbors) {
                if (!copies.count(neighbor)) {
                    copies[neighbor] = new Node(neighbor->val);
                    pending.push(neighbor);
                }
                copies[current]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copies[node];
    }
};

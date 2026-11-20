class Solution {
    public: vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        function<void(TreeNode*)> visit = [&](TreeNode* node) {
            if (!node) return;
            size_t previous = path.size();
            if (!path.empty()) path += "->";
            path += to_string(node->val);
            if (!node->left && !node->right) result.push_back(path);
            else {
                visit(node->left);
                visit(node->right);
            }
            path.resize(previous);
        };
        visit(root);
        return result;
    }
};

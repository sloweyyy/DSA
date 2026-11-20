class Solution {
    public: TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* next = root->right;
            while (next->left) next = next->left;
            root->val = next->val;
            root->right = deleteNode(root->right, next->val);
        }
        return root;
    }
};

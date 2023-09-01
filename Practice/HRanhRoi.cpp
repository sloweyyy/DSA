#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(Node *&root, int val) {
    if (root == nullptr) {
        root = new Node(val);
        return;
    }
    if (val < root->value) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

void countLeaves(Node *root, int &count, vector<int> &leaves) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        count++;
        leaves.push_back(root->value);
    }
    countLeaves(root->left, count, leaves);
    countLeaves(root->right, count, leaves);
}

int main() {
    int n;
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(root, val);
    }
    int count = 0;
    vector<int> leaves;
    countLeaves(root, count, leaves);
    cout << count << endl;
    for (int leaf : leaves) {
        cout << leaf << " ";
    }
    return 0;
}

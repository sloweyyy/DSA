#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        if (root == NULL)
            return;
        queue<pair<Node*, int>> q;
        map<int, int> m;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<Node*, int> p = q.front();
            q.pop();
            if (m.find(p.second) == m.end())
                m[p.second] = p.first->data;
            if (p.first->left != NULL)
                q.push(make_pair(p.first->left, p.second - 1));
            if (p.first->right != NULL)
                q.push(make_pair(p.first->right, p.second + 1));
        }
        for (auto i = m.begin(); i != m.end(); i++)
            cout << i->second << " ";
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
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

    void levelOrder(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();
            cout << n->data << " ";
            if (n->left != NULL)
                q.push(n->left);
            if (n->right != NULL)
                q.push(n->right);
        }
    }

    void removeNode(Node *root, int data)
    {
        if (root == NULL)
            return;
        if (root->data == data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                Node *temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;
                root->data = temp->data;
                removeNode(root->right, temp->data);
            }
        }
        else if (root->data > data)
            removeNode(root->left, data);
        else
            removeNode(root->right, data);
    }
};

bool checkBST(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!checkBST(root->left))
            return false;
        if (prev != NULL && root->data <= prev->data)
            return false;
        prev = root;
        return checkBST(root->right);
    }
    return true;
}
int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.levelOrder(root);
    return 0;
}

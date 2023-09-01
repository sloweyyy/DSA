
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

    /* you only have to complete the function given below.
    Node is defined as

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

    void preOrder(Node *root)
    {
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *popped = s.top();
            s.pop();
            cout << popped->data << " ";
            if (popped->right != NULL)
            {
                s.push(popped->right);
            }
            if (popped->left != NULL)
            {
                s.push(popped->left);
            }
        }
    }

    void postOrder(Node *root)
    {
        stack<Node *> s;
        s.push(root);
        stack<int> out;
        while (!s.empty())
        {
            Node *popped = s.top();
            s.pop();
            if (popped->left != NULL)
            {
                s.push(popped->left);
            }
            if (popped->right != NULL)
            {
                s.push(popped->right);
            }
            out.push(popped->data);
        }
        while (!out.empty())
        {
            cout << out.top() << " ";
            out.pop();
        }
    }

    void inOrder(Node *root)
    {
        stack<Node *> s;
        Node *curr = root;
        while (curr != NULL || !s.empty())
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    void levelOrder(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *popped = q.front();
            q.pop();
            cout << popped->data << " ";
            if (popped->left != NULL)
            {
                q.push(popped->left);
            }
            if (popped->right != NULL)
            {
                q.push(popped->right);
            }
        }
    }

}; // End of Solution

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

    myTree.postOrder(root);

    return 0;
}
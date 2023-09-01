#include <iostream>

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

bool isFullTree(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if ((root->left) && (root->right))
        return (isFullTree(root->left) && isFullTree(root->right));
    return false;
}
int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    cin >> t;

    while (t-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
    if (isFullTree(root))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

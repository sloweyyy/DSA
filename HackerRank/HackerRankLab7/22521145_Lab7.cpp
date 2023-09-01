#include "iostream"
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    void FindReplace(Node *&root, Node *&temp)
    {
        if (root->left)
        {
            FindReplace(root->left, temp);
        }
        else
        {
            temp->data = root->data;
            temp = root;
            root = root->right;
        }
    }

public:
    Node *add(Node *root, int data)
    {
        if (!root)
        {
            return new Node(data);
        }
        else
        {
            Node *p;
            if (data <= root->data)
            {
                p = add(root->left, data);
                root->left = p;
            }
            else
            {
                p = add(root->right, data);
                root->right = p;
            }
            return root;
        }
    }
    int EvenSum(Node *root, int &S)
    {
        if (root)
        {
            if (root->data % 2 == 0)
            {
                S += root->data;
            }
            EvenSum(root->left, S);
            EvenSum(root->right, S);
        }
        return S;
    }
    void Output(Node *root)
    {
        if (root)
        {
            cout << root->data << " ";
            Output(root->left);
            Output(root->right);
        }
    }

    void RemoveNode(Node *&root, int x)
    {
        if (!root)
        {
            cout << "Not found!" << endl;
        }
        else
        {
            if (x < root->data)
                RemoveNode(root->left, x);
            else if (x > root->data)
                RemoveNode(root->right, x);
            else
            {
                Node *nodedelete = root;
                if (root->left == NULL)
                {
                    root = root->right;
                }
                else if (root->right == NULL)
                {
                    root = root->left;
                }
                else
                {
                    FindReplace(root->right, nodedelete);
                }
                delete nodedelete;
            }
        }
    }
};

int main()
{
    Solution Tree;
    Node *root = NULL;
    int t;
    int data;
    cin >> t;
    while (t-- != 0)
    {
        cin >> data;
        root = Tree.add(root, data);
    }
    int S = 0;
    cout << "Tong gia tri cac khoa chan: " << Tree.EvenSum(root, S) << endl;
    Tree.Output(root);
    int x;
    cout << endl;
    cin >> x;
    Tree.RemoveNode(root, x);
    cout << "Cay sau khi da xoa la: " << endl;
    Tree.Output(root);
    cout << endl;
    return 0;
}
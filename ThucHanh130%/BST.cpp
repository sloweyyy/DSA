#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    return new Node{data, nullptr, nullptr};
}

Node *insertNode(Node *root, int data)
{
    if (root == nullptr)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

bool searchNode(const Node *root, int data)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (data == root->data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

Node *findMin(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void deleteTree(Node *&root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *root = nullptr;
    int type, ID;
    cin >> type >> ID;
    while (type != 0)
    {
        switch (type)
        {
        case 1:
            root = insertNode(root, ID);
            break;
        case 2:
            if (searchNode(root, ID))
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
            break;
        case 3:
            root = deleteNode(root, ID);
            break;
        }
        cin >> type >> ID;
    }

    deleteTree(root);
    return 0;
}

#include <iostream>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createNode(int value)
{
    return new TreeNode{value, nullptr, nullptr};
}

TreeNode *insertNode(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

bool searchNode(const TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (value == root->value)
    {
        return true;
    }
    else if (value < root->value)
    {
        return searchNode(root->left, value);
    }
    else
    {
        return searchNode(root->right, value);
    }
}

TreeNode *findMin(TreeNode *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

TreeNode *deleteNode(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (value < root->value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = deleteNode(root->right, value);
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
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            TreeNode *temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    return root;
}

void deleteTree(TreeNode *&root)
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
    TreeNode *root = nullptr;
    int operation, value;
    scanf("%d %d", &operation, &value);
    while (operation != 0)
    {
        switch (operation)
        {
        case 1:
            root = insertNode(root, value);
            break;
        case 2:
            if (searchNode(root, value))
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
            break;
        case 3:
            root = deleteNode(root, value);
            break;
        }
        scanf("%d %d", &operation, &value);
    }

    deleteTree(root);
    return 0;
}
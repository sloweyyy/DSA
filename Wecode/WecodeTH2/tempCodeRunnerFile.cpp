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

    int min_width = -1, max_width = 1, current_width = 0;
    void inorder(Node *root, int current_width)
    {
        if (root == NULL)
            return;
        if (current_width < min_width)
            min_width = current_width;
        if (current_width > max_width)
            max_width = current_width;
        if (root->left != NULL)
            inorder(root->left, current_width - 1);
        if (root->right != NULL)
            inorder(root->right, current_width + 1);
    }
    void top(Node *root, int arr[], int current_width, int h, int arr2[])
    {
        if (root == NULL)
            return;
        if (arr[current_width - min_width] == 0 || h < arr2[current_width - min_width])
        {
            arr2[current_width - min_width] = h;
            arr[current_width - min_width] = root->data;
        }
        if (root->left != NULL)
            top(root->left, arr, current_width - 1, h + 1, arr2);
        if (root->right != NULL)
            top(root->right, arr, current_width + 1, h + 1, arr2);
    }
    void topView(Node *root)
    {
        inorder(root, 0);
        int arr[max_width - min_width + 1], arr1[max_width - min_width + 1];
        for (int i = 0; i < max_width - min_width + 1; i++)
        {
            arr[i] = 0;
            arr1[i] = 90;
        }
        top(root, arr, 0, 1, arr1);
        sort(arr, arr + max_width - min_width + 1);
        for (int i = 0; i < max_width - min_width + 1; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

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
        myTree.topView(root);
        return 0;
    }

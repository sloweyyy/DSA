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

    void inOrder(Node *root, int current_width, int &min_width, int &max_width)
    {
        if (root == NULL)
            return;
        if (current_width < min_width)
            min_width = current_width;
        if (current_width > max_width)
            max_width = current_width;
        inOrder(root->left, current_width - 1, min_width, max_width);
        inOrder(root->right, current_width + 1, min_width, max_width);
    }

    void top(Node *root, int *arr, int current_width, int h, int *arr1, int min_width)
    {
        if (root == NULL)
            return;
        int index = current_width - min_width;
        if (arr[index] == 0 || h < arr1[index])
        {
            arr1[index] = h;
            arr[index] = root->data;
        }
        top(root->left, arr, current_width - 1, h + 1, arr1, min_width);
        top(root->right, arr, current_width + 1, h + 1, arr1, min_width);
    }

    void topView(Node *root)
    {
        int min_width = 0, max_width = 0;
        inOrder(root, 0, min_width, max_width);
        int size = max_width - min_width + 1;
        int *arr = new int[size];
        int *arr1 = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
            arr1[i] = 90;
        }
        top(root, arr, 0, 1, arr1, min_width);
        sort(arr, arr + size);
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0)
            {
                cout << arr[i] << " ";
            }
        }
        delete[] arr;
        delete[] arr1;
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
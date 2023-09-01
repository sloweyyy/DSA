#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
    int n;             // số khóa hiện tại
    int keys[4];       // mảng chứa khóa
    Node *children[5]; // mảng con trỏ trỏ đến các nút con
    bool leaf;         // đánh dấu nút lá
};

// Tạo nút mới
Node *createNode(int key)
{
    Node *newNode = new Node;
    newNode->n = 1;
    newNode->keys[0] = key;
    for (int i = 0; i < 5; i++)
    {
        newNode->children[i] = NULL;
    }
    newNode->leaf = true;
    return newNode;
}
void splitChild(Node *node, int i, Node *child)
{
    Node *newNode = createNode(0);
    newNode->leaf = child->leaf;
    newNode->n = 2;
    for (int j = 0; j < 2; j++)
    {
        newNode->keys[j] = child->keys[j + 3];
    }
    if (!child->leaf)
    {
        for (int j = 0; j < 3; j++)
        {
            newNode->children[j] = child->children[j + 3];
        }
    }
    child->n = 2;
    for (int j = node->n; j >= i + 1; j--)
    {
        node->children[j + 1] = node->children[j];
    }
    node->children[i + 1] = newNode;
    for (int j = node->n - 1; j >= i; j--)
    {
        node->keys[j + 1] = node->keys[j];
    }
    node->keys[i] = child->keys[2];
    node->n++;
}

// Thêm khóa vào nút đã có sẵn
void insertNonFull(Node *node, int key)
{
    int i = node->n - 1;
    if (node->leaf)
    {
        while (i >= 0 && node->keys[i] > key)
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    }
    else
    {
        while (i >= 0 && node->keys[i] > key)
        {
            i--;
        }
        if (node->children[i + 1]->n == 4)
        {
            splitChild(node, i + 1, node->children[i + 1]);
            if (node->keys[i + 1] < key)
            {
                i++;
            }
        }
        insertNonFull(node->children[i + 1], key);
    }
}

// Chia nút con khi nút con đầy

// Chèn khóa vào cây
void insert(Node *&root, int key)
{
    if (root == NULL)
    {
        root = createNode(key);
    }
    else
    {
        if (root->n == 4)
        {
            Node *newNode = createNode(0);
            newNode->leaf = false;
            newNode->n = 0;
            newNode->children[0] = root;
            splitChild(newNode, 0, root);
            int i = 0;
            if (newNode->keys[0] < key)
            {
                i++;
            }
            insertNonFull(newNode->children[i], key);
            root = newNode;
        }
        else
        {
            insertNonFull(root, key);
        }
    }
}

// Thêm khóa theo chiến lược proactive
void insertProactive(Node *&root, int key)
{
    if (root == NULL)
    {
        root = createNode(key);
    }
    else
    {
        int i = 0;
        while (i < root->n && root->keys[i] < key)
        {
            i++;
        }
        if (root->keys[i] != key)
        {
            insert(root, key);
        }
    }
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int maxChildHeight = 0;
        for (int i = 0; i < root->n + 1; i++)
        {
            int childHeight = height(root->children[i]);
            if (childHeight > maxChildHeight)
            {
                maxChildHeight = childHeight;
            }
        }
        return maxChildHeight + 1;
    }
}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        for (int i = 0; i < root->n; i++)
        {
            cout << root->keys[i] << " ";
        }
        for (int i = 0; i < root->n + 1; i++)
        {
            preOrder(root->children[i]);
        }
    }
}
void borrowFromLeft(Node *&root, int i)
{
    Node *leftSibling = root->children[i - 1];
    Node *rightSibling = root->children[i];
    for (int j = rightSibling->n - 1; j >= 0; j--)
    {
        rightSibling->keys[j + 1] = rightSibling->keys[j];
    }
    rightSibling->keys[0] = root->keys[i - 1];
    if (!rightSibling->leaf)
    {
        for (int j = rightSibling->n; j >= 0; j--)
        {
            rightSibling->children[j + 1] = rightSibling->children[j];
        }
        rightSibling->children[0] = leftSibling->children[leftSibling->n];
    }
    root->keys[i - 1] = leftSibling->keys[leftSibling->n - 1];
    rightSibling->n++;
    leftSibling->n--;
}

void borrowFromRight(Node *&root, int i)
{
    Node *leftSibling = root->children[i];
    Node *rightSibling = root->children[i + 1];
    leftSibling->keys[leftSibling->n] = root->keys[i];
    if (!leftSibling->leaf)
    {
        leftSibling->children[leftSibling->n + 1] = rightSibling->children[0];
    }
    root->keys[i] = rightSibling->keys[0];
    for (int j = 1; j < rightSibling->n; j++)
    {
        rightSibling->keys[j - 1] = rightSibling->keys[j];
    }
    if (!rightSibling->leaf)
    {
        for (int j = 1; j <= rightSibling->n; j++)
        {
            rightSibling->children[j - 1] = rightSibling->children[j];
        }
    }
    leftSibling->n++;
    rightSibling->n--;
}
void mergeChildren(Node *&root, int i)
{
    Node *leftChild = root->children[i];
    Node *rightChild = root->children[i + 1];
    leftChild->keys[2] = root->keys[i];
    for (int j = 0; j < 2; j++)
    {
        leftChild->keys[j + 3] = rightChild->keys[j];
    }
    if (!leftChild->leaf)
    {
        for (int j = 0; j < 3; j++)
        {
            leftChild->children[j + 5] = rightChild->children[j];
        }
    }
    for (int j = i; j < root->n - 1; j++)
    {
        root->keys[j] = root->keys[j + 1];
        root->children[j + 1] = root->children[j + 2];
    }
    root->n--;
    delete rightChild;
}
void fillChild(Node *&root, int i)
{
    if (i > 0 && root->children[i - 1]->n >= 2)
    {
        borrowFromLeft(root, i);
    }
    else if (i < root->n && root->children[i + 1]->n >= 2)
    {
        borrowFromRight(root, i);
    }
    else
    {
        if (i < root->n)
        {
            mergeChildren(root, i);
        }
        else
        {
            mergeChildren(root, i - 1);
        }
    }
}
int getSuccessor(Node *node)
{
    while (!node->leaf)
    {
        node = node->children[0];
    }
    return node->keys[0];
}
int getPredecessor(Node *node)
{
    while (!node->leaf)
    {
        node = node->children[node->n];
    }
    return node->keys[node->n - 1];
}
void remove(Node *&root, int key)
{
    if (root == NULL)
    {
        return;
    }
    int i = 0;
    while (i < root->n && root->keys[i] < key)
    {
        i++;
    }
    if (i < root->n && root->keys[i] == key)
    {
        if (root->leaf)
        {
            for (int j = i; j < root->n - 1; j++)
            {
                root->keys[j] = root->keys[j + 1];
            }
            root->n--;
        }
        else
        {
            if (root->children[i]->n >= 2)
            {
                int predecessor = getPredecessor(root->children[i]);
                root->keys[i] = predecessor;
                remove(root->children[i], predecessor);
            }
            else if (root->children[i + 1]->n >= 2)
            {
                int successor = getSuccessor(root->children[i + 1]);
                root->keys[i] = successor;
                remove(root->children[i + 1], successor);
            }
            else
            {
                mergeChildren(root, i);
                remove(root->children[i], key);
            }
        }
    }
    else
    {
        if (root->children[i]->n < 2)
        {
            fillChild(root, i);
        }
        remove(root->children[i], key);
    }
}









// Xóa khóa x khỏi cây
void deleteKey(Node *&root, int x)
{
    remove(root, x);
}

int main()
{
    srand(time(NULL));
    Node *root = NULL;
    int n;
    cout << "Nhap so luong khoa: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        insertProactive(root, key);
    }
    cout << "Chieu cao cua cay: " << height(root) << endl;
    cout << "Duyet theo thu tu truoc: ";
    preOrder(root);
    int x;
    cout << "\nNhap khoa can xoa: ";
    cin >> x;
    deleteKey(root, x);
    cout << "Duyet theo thu tu truoc: ";
    preOrder(root);

    return 0;
}

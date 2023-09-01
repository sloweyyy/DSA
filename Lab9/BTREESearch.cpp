#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Item
{
    string word;
    string meaning;
};

struct NodeTree
{
    string key;
    string value;
    NodeTree *left;
    NodeTree *right;
    NodeTree *parent;
    int size;
};

void loadData(const char file[], Item dat[], int &n)
{
    ifstream fi(file);
    if (!fi.is_open())
    {
        cout << "Khong mo duoc file de tu dien" << endl;
        return;
    }
    string s;
    int b, e;
    n = 0;
    while (!fi.eof())
    {
        getline(fi, s);
        b = s.find("\t");
        if (b < 0)
            continue;
        dat[n].word = s.substr(0, b);
        s = s.substr(b + 1);
        while ((b = s.find("|=")) > -1)
        {
            s.replace(b, 2, "\n");
        }
        dat[n].meaning = s;
        n++;
    }
    fi.close();
}

void insertTree(NodeTree *&root, string key, string value)
{
    NodeTree *node = new NodeTree;
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->size = 1;

    if (root == NULL)
    {
        root = node;
        return;
    }

    NodeTree *curr = root;
    NodeTree *prev = NULL;
    while (curr != NULL)
    {
        prev = curr;
        if (key < curr->key)
        {
            curr->size++;
            curr = curr->left;
        }
        else if (key > curr->key)
        {
            curr->size++;
            curr = curr->right;
        }
        else
        {
            curr->value = value;
            return;
        }
    }

    node->parent = prev;
    if (key < prev->key)
    {
        prev->left = node;
    }
    else
    {
        prev->right = node;
    }

    while (prev != NULL)
    {
        prev->size++;
        prev = prev->parent;
    }
}

string searchTree(NodeTree *root, string key)
{
    NodeTree *curr = root;
    while (curr != NULL)
    {
        if (key < curr->key)
        {
            curr = curr->left;
        }
        else if (key > curr->key)
        {
            curr = curr->right;
        }
        else
        {
            return curr->value;
        }
    }
    return "Khong tim thay tu nay trong tu dien";
}

string getRandomWord(NodeTree *root)
{
    int k = rand() % root->size + 1;
    NodeTree *curr = root;
    while (curr != NULL)
    {
        int leftSize = (curr->left != NULL) ? curr->left->size : 0;
        if (k <= leftSize)
        {
            curr = curr->left;
        }
        else if (k == leftSize + 1)
        {
            return curr->key;
        }
        else
        {
            k -= leftSize + 1;
            curr = curr->right;
        }
    }
    return "";
}

int main()
{
    Item *data = new Item[13375];
    int n;
    clock_t start;
    start = clock();

    cout << "Tai du lieu tu dien" << endl;
    loadData("mcomputer.txt", data, n);
    cout << "Tong so tu vung: " << n << endl;
    cout << "Thoi gian tai du lieu: " << clock() - start << "ms" << endl;

    NodeTree *root = NULL;
    for (int i = 0; i < n; i++)
    {
        insertTree(root, data[i].word, data[i].meaning);
    }
    delete[] data;

    string word;
    while (1)
    {
        cout << "Nhap tu can tra (EXIT de thoat): ";
        getline(cin, word);
        if (word == "EXIT")
            break;
        start = clock();
        string meaning = searchTree(root, word);
        cout << meaning << endl;
        cout << "Thoi gian tim: " << clock() - start << "ms" << endl;
    }
    
    start = clock();
    for (int i = 0; i < 1000; i++)
    {
        string word = getRandomWord(root);
        string meaning = searchTree(root, word);
    }
    cout << "Thoi gian tim random 1000 tu cay: " << clock() - start << "ms" << endl;

    system("pause");
    return 0;
}

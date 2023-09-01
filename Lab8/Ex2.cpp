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

struct BTreeNode
{
    string key[4];
    string value[4];
    BTreeNode *child[5];
    BTreeNode *parent; 
    int count;
    bool leaf;
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

void insertTree(BTreeNode *&root, string key, string value)
{
    if (root == NULL)
    {
        root = new BTreeNode;
        root->key[0] = key;
        root->value[0] = value;
        root->count = 1;
        root->leaf = true;
        root->parent = NULL;
        for (int i = 0; i < 5; i++)
        {
            root->child[i] = NULL;
        }
        return;
    }

    if (root->count < 4)
    {
        int i = root->count - 1;
        while (i >= 0 && key < root->key[i])
        {
            root->key[i + 1] = root->key[i];
            root->value[i + 1] = root->value[i];
            i--;
        }
        root->key[i + 1] = key;
        root->value[i + 1] = value;
        root->count++;
        root->leaf = true;
        return;
    }

    BTreeNode *newNode = new BTreeNode;
    newNode->count = 0;
    newNode->leaf = false;
    for (int i = 0; i < 5; i++)
    {
        newNode->child[i] = NULL;
    }

    if (key < root->key[2])
    {
        newNode->child[0] = root->child[2];
        root->child[2] = NULL;
        for (int i = 3; i < 5; i++)
        {
            newNode->child[i - 2] = root->child[i];
            root->child[i] = NULL;
        }
        newNode->key[0] = root->key[3];
        newNode->value[0] = root->value[3];
        newNode->count++;
        root->count = 2;
        insertTree(root, key, value);
    }
    else if (key > root->key[2])
    {
        newNode->child[0] = root->child[3];
        root->child[3] = NULL;
        root->count = 2;
        newNode->count = 1;
        newNode->key[0] = root->key[4];
        newNode->value[0] = root->value[4];
        insertTree(newNode, key, value);
    }
    else
    {
        root->value[2] = value;
    }

    if (root->parent == NULL)
    {
        BTreeNode *newRoot = new BTreeNode;
        newRoot->key[0] = root->key[2];
        newRoot->value[0] = root->value[2];
        newRoot->count = 1;
        newRoot->leaf = false;
        newRoot->child[0] = root;
        newRoot->child[1] = newNode;
        root->parent = newRoot;
        newNode->parent = newRoot;
        for (int i = 2; i < 5; i++)
        {
            newRoot->child[i] = NULL;
        }
        root = newRoot;
    }
    else
    {
        insertTree(root->parent, newNode->key[0], newNode->value[0]);
        newNode->parent = root->parent;
    }
}

string searchTree(BTreeNode *root, string key)
{
    if (root == NULL)
    {
        return "Khong tim thay tu nay trong tu dien";
    }

    int i = 0;
    while (i < root->count && key > root->key[i])
    {
        i++;
    }

    if (i < root->count && key == root->key[i])
    {
        return root->value[i];
    }

    if (root->leaf)
    {
        return "Khong tim thay tu nay trong tu dien";
    }

    return searchTree(root->child[i], key);
}

string getRandomWord(BTreeNode *root)
{
    int k = rand() % root->count + 1;
    BTreeNode *curr = root;
    while (!curr->leaf)
    {
        int i;
        for (i = 0; i < curr->count; i++)
        {
            if (k <= i + 1)
            {
                curr = curr->child[i];
                break;
            }
            k -= i + 1;
        }
        if (i == curr->count)
        {
            curr = curr->child[i];
        }
    }
    return curr->key[k - 1];
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

    BTreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        insertTree(root, data[i].word, data[i].meaning);
    }
    delete[] data;

    string word;
    while (1)
    {
        cout << "Nhap tu can tra (EXIT de thoat, RANDOM de lay tu ngau nhien): ";
        getline(cin, word);
        if (word == "EXIT")
            break;
        if (word == "RANDOM")
        {
            start = clock();
            word = getRandomWord(root);
            cout << "Tu ngau nhien: " << word << endl;
            cout << "Thoi gian tim: " << clock() - start << "ms" << endl;
            continue;
        }
        start = clock();
        string meaning = searchTree(root, word);
        cout << meaning << endl;
        cout << "Thoi gian tim: " << clock() - start << "ms" << endl;
    }
    system("pause");
    return 0;
}

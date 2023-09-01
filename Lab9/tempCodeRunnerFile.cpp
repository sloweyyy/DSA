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

struct NodeHash
{
    Item data;
    NodeHash *next;
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

const int mySize = 15000;
NodeHash *hashTable[mySize];

void loadData(char file[], Item dat[], int &n)
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
    while (getline(fi, s))
    {
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
// hash
int _hash(string s, int mySize)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i];
    }
    return sum % mySize;
}

int doubleHash(string s, int mySize)
{
    int hashVal = _hash(s, mySize);
    int stepSize = 13 - (hashVal % 13);
    int i = 1;
    while (hashTable[hashVal] != NULL && hashTable[hashVal]->data.word != s)
    {
        hashVal = (hashVal + i * stepSize) % mySize;
        i++;
    }
    return hashVal;
}

void insertHash(Item item, int mySize)
{
    int hashVal = doubleHash(item.word, mySize);
    NodeHash *newNode = new NodeHash;
    newNode->data = item;
    newNode->next = hashTable[hashVal];
    hashTable[hashVal] = newNode;
}

bool searchHash(string word, int mySize, string &meaning)
{
    int hashVal = doubleHash(word, mySize);
    NodeHash *node = hashTable[hashVal];
    while (node != NULL && node->data.word != word)
    {
        node = node->next;
    }
    if (node == NULL)
    {
        return false;
    }
    else
    {
        meaning = node->data.meaning;
        return true;
    }
}
// tree
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

bool searchTree(NodeTree *root, string key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key == key)
    {
        return true;
    }
    if (key < root->key)
    {
        return searchTree(root->left, key);
    }
    else
    {
        return searchTree(root->right, key);
    }
}
int main()
{
    Item *data = new Item[15000];
    int n;
    clock_t start;
    start = clock();
    cout << "Tai du lieu tu dien" << endl;
    loadData("mcomputer.txt", data, n);
    cout << "Tong so tu vung: " << n << endl;
    cout << "Thoi gian tai du lieu: " << clock() - start << "ms" << endl;
    int type;
    cout << "Chon chuc nang: " << endl;
    cout << "1. Tim kiem bang mang bam." << endl;
    cout << "2. So sanh hieu suat tim kiem 1000 tu giua mang bam va cay tim kiem." << endl;
    cin >> type;
    string word;
    switch (type)
    {
    case 1:
        // Tao bang bam
        for (int i = 0; i < mySize; i++)
        {
            hashTable[i] = NULL;
        }
        for (int i = 0; i < n; i++)
        {
            insertHash(data[i], mySize);
        }

        // Tra tu bang bang bam
        while (1)
        {
            cout << "Nhap tu can tra (EXIT de thoat): ";
            cin.ignore();
            getline(cin, word);
            if (word == "EXIT")
                break;
            start = clock();
            string meaning;
            if (!searchHash(word, mySize, meaning))
            {
                cout << "Khong tim thay tu" << endl;
            }
            else
            {
                cout << meaning << endl;
            }
            cout << "Thoi gian tim: " << clock() - start << "ms" << endl;
        }
        break;
    case 2:
        // searchHash random 1000 word and calculate average time
        int total = 0;
        // create a array of random index
        int *randomIndex = new int[1000];
        srand(time(NULL));
        for (int i = 0; i < 1000; i++)
        {
            randomIndex[i] = rand() % n;
        }
        start = clock();
        for (int i = 0; i < 1000; i++)
        {
            string meaning;
            searchHash(data[randomIndex[i]].word, mySize, meaning);
        }
        cout << "Thoi gian tim 1000 tu bang mang bam: " << clock() - start << "ms" << endl;
        // search 1000 tu cay
        NodeTree *root = NULL;
        start = clock();
        for (int i = 0; i < 1000; i++)
        {
            searchTree(root, data[randomIndex[i]].word);
        }
        cout << "Thoi gian tim random 1000 tu bang cay: " << clock() - start << "ms" << endl;
        break;
    }
    delete[] data;
    system("pause");
    return 0;
}
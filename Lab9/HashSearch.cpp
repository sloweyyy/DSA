// #include <iostream>
// #include <fstream>
// #include <string>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// struct Item
// {
//     string word;
//     string meaning;
// };

// struct HashTable
// {
//     Item *table;
//     int size;
//     int count;
// };

// int hashFunction(const string &key, int tableSize)
// {
//     int hashVal = 0;
//     for (int i = 0; i < key.length(); i++)
//         hashVal = 37 * hashVal + key[i];
//     hashVal %= tableSize;
//     if (hashVal < 0)
//         hashVal += tableSize;
//     return hashVal;
// }

// void initHashTable(HashTable &ht, int size)
// {
//     ht.table = new Item[size];
//     ht.size = size;
//     ht.count = 0;
//     for (int i = 0; i < size; i++)
//     {
//         ht.table[i].word = "";
//         ht.table[i].meaning = "";
//     }
// }

// void insertItem(HashTable &ht, const Item &item)
// {
//     int index = hashFunction(item.word, ht.size);
//     while (ht.table[index].word != "" && ht.table[index].word != item.word)
//     {
//         index++;
//         if (index >= ht.size)
//             index = 0;
//     }
//     ht.table[index] = item;
//     ht.count++;
// }

// string searchItem(HashTable &ht, const string &key)
// {
//     int index = hashFunction(key, ht.size);
//     while (ht.table[index].word != "" && ht.table[index].word != key)
//     {
//         index++;
//         if (index >= ht.size)
//             index = 0;
//     }
//     if (ht.table[index].word == key)
//         return ht.table[index].meaning;
//     else
//         return "";
// }

// void loadData(const char file[], HashTable &ht)
// {
//     ifstream fi(file);
//     if (!fi.is_open())
//     {
//         cout << "Khong mo duoc file de tu dien" << endl;
//         return;
//     }
//     string s;
//     int b, e;
//     while (!fi.eof())
//     {
//         getline(fi, s);
//         b = s.find("\t");
//         if (b < 0)
//             continue;
//         Item item;
//         item.word = s.substr(0, b);
//         s = s.substr(b + 1);
//         while ((b = s.find("|=")) > -1)
//         {
//             s.replace(b, 2, "\n");
//         }
//         item.meaning = s;
//         insertItem(ht, item);
//     }
//     fi.close();
// }

// int main()
// {
//     HashTable ht;
//     initHashTable(ht, 13375);
//     Item *data = new Item[13375];
//     int n;
//     clock_t start;
//     start = clock();
//     cout << "Tai du lieu tu dien" << endl;
//     loadData("mcomputer.txt", ht);
//     cout << "Tong so tu vung: " << n << endl;
//     cout << "Thoi gian tai du lieu: " << clock() - start << "ms" << endl;
//     string word;
//     while (1)
//     {
//         cout << "Nhap tu can tra (EXIT de thoat): ";
//         getline(cin, word);
//         if (word == "EXIT")
//             break;
//         start = clock();
//         // Goi ham va in ket qua tim duoc
//         searchItem(ht, word);
//         // ------------------------------
//         cout << "Thoi gian tim: " << clock() - start << "ms" << endl;
//     }
//     // test search performance
//     srand(time(0));
//     const int numWords = 1000;
//     string words[numWords];
//     for (int i = 0; i < numWords; i++)
//     {
//         int index = rand() % ht.count;
//         words[i] = ht.table[index].word;
//     }

//     start = clock();
//     for (int i = 0; i < numWords; i++)
//     {
//         searchItem(ht, words[i]);
//     }
//     cout << "Thoi gian tim bang bam: " << clock() - start << "ms" << endl;

//     delete[] ht.table;
//     system("pause");
//     return 0;
// }

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

struct Node
{
    Item data;
    Node *next;
};

const int mySize = 15000;
Node *hashTable[mySize];

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
    int stepSize = 7 - (hashVal % 7);
    int i = 1;
    while (hashTable[hashVal] != NULL && hashTable[hashVal]->data.word != s)
    {
        hashVal = (hashVal + i * stepSize) % mySize;
        i++;
    }
    return hashVal;
}

void insert(Item item, int mySize)
{
    int hashVal = doubleHash(item.word, mySize);
    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = hashTable[hashVal];
    hashTable[hashVal] = newNode;
}

string search(string word, int mySize)
{
    int hashVal = doubleHash(word, mySize);
    Node *node = hashTable[hashVal];
    while (node != NULL && node->data.word != word)
    {
        node = node->next;
    }
    if (node == NULL)
    {
        return "";
    }
    else
    {
        return node->data.meaning;
    }
}
string searchItem(hashTable &ht, const string &key)
{
    int index = hashFunction(key, ht.size);
    while (ht.table[index].word != "" && ht.table[index].word != key)
    {
        index++;
        if (index >= ht.size)
            index = 0;
    }
    if (ht.table[index].word == key)
        return ht.table[index].meaning;
    else
        return "";
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

    // Tao bang bam
    for (int i = 0; i < mySize; i++)
    {
        hashTable[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        insert(data[i], mySize);
    }

    // Tra tu bang bang bam
    string word;
    while (1)
    {
        cout << "Nhap tu can tra (EXIT de thoat): ";
        getline(cin, word);
        if (word == "EXIT")
            break;
        start = clock();
        string meaning = search(word, mySize);
        if (meaning == "")
        {
            cout << "Khong tim thay tu" << endl;
        }
        else
        {
            cout << meaning << endl;
        }
        cout << "Thoi gian tim: " << clock() - start << "ms" << endl;
    }
    // test search performance
    srand(time(0));
    const int numWords = 1000;
    string words[numWords];
    for (int i = 0; i < numWords; i++)
    {
        int index = rand() % ht.count;
        words[i] = ht.table[index].word;
    }

    start = clock();
    for (int i = 0; i < numWords; i++)
    {
        searchItem(ht, words[i]);
    }
    cout << "Thoi gian tim bang bam: " << clock() - start << "ms" << endl;

    delete[] data;
    system("pause");
    return 0;
}
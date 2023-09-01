#include <iostream>
using namespace std;

int hashFunction(int key, int size)
{
    return key % size;
}

int reHash(int key, int index, int size)
{
    return (hashFunction(key, size) + index * index) % size;
}

void insertIntoHashTable(int hashTable[], int key, int size)
{
    int index = hashFunction(key, size);
    int i = 0;
    while (hashTable[index] != 0)
    {
        if (hashTable[index] == key)
        {
            cout << "FULL" << endl;
            return;
        }
        i++;
        index = reHash(key, i, size);
    }
    hashTable[index] = key;
}

int main()
{
    int m, n;
    cin >> m >> n;

    int *hashTable = new int[m];
    for (int i = 0; i < m; i++)
    {
        hashTable[i] = 0;
    }

    int key;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        insertIntoHashTable(hashTable, key, m);
    }

    int emptySlots = 0;
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] == 0)
        {
            emptySlots++;
        }
    }

    cout << emptySlots << endl;
    delete[] hashTable;
    return 0;
}

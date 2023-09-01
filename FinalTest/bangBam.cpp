#include <iostream>
#include <vector>

using namespace std;

void insertElement(vector<int> &hashTable, int element)
{
    int m = hashTable.size();
    int key = element % m;
    int i = 0;
    while (hashTable[key] != 0 && hashTable[key] != -1)
    {
        key = (key + i * i) % m;
        i++;
        if (i >= m)
        {
            // Hash table is full
            return;
        }
    }
    hashTable[key] = element;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> hashTable(m, 0);

    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        int key = element % m;
        int j = 0;
        bool inserted = false;
        while (hashTable[key] != 0 && hashTable[key] != -1)
        {
            key = (key + j * j) % m;
            j++;
            if (j >= m)
            {
                // Hash table is full
                inserted = true;
                break;
            }
        }
        if (!inserted)
        {
            insertElement(hashTable, element);
        }
        else
        {
            cout << element << " FULL" << endl;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] == 0 || hashTable[i] == -1)
        {
            cout << i << endl;
        }
    }
    return 0;
}

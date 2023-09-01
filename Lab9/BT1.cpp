#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *next;
    Node(int k) : key(k), next(NULL) {}
};

class HashMap
{
private:
    Node **table; 
    int size;   
    int hash(int key)
    {
        return key % size;
    }

public:
    HashMap(int s)
    {
        size = s;
        table = new Node *[size]; 
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL; 
        }
    }
    ~HashMap()
    {
        for (int i = 0; i < size; i++)
        {
            Node *curr = table[i];
            while (curr != NULL)
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp; 
            }
        }
        delete[] table; 
    }
    void put(int key)
    {
        int index = hash(key);
        Node *node = new Node(key);
        if (table[index] == NULL)
        {
            table[index] = node;
        }
        else
        {
            Node *curr = table[index];
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = node;
        }
    }
    void search(int key)
    {
        int index = hash(key);
        Node *curr = table[index];
        while (curr != NULL)
        {
            if (curr->key == key)
            {
                cout << "Found " << key << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Not found " << key << endl;
    }

    void remove(int key)
    {
        int index = hash(key);
        Node *curr = table[index];
        Node *prev = NULL;
        while (curr != NULL)
        {
            if (curr->key == key)
            {
                if (prev == NULL)
                {
                    table[index] = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Removed " << key << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Not found " << key << endl;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            Node *curr = table[i];
            while (curr != NULL)
            {
                cout << curr->key << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap map(20);
    // add 1, 28, 38, 152, 31, 112, 77, 4, 271, 149
    map.put(1);
    map.put(28);
    map.put(38);
    map.put(152);
    map.put(31);
    map.put(112);
    map.put(77);
    map.put(4);
    map.put(271);
    map.put(149);
    // print
    map.print();
    // search 1, 38, 112, 75.
    map.search(1);
    map.search(38);
    map.search(112);
    map.search(75);
    // remove 1, 75, 112.
    map.remove(1);
    map.remove(75);
    map.remove(112);
    // print
    map.print();
    // search 38, 112, 149. 
    map.search(38);
    map.search(112);
    map.search(149);
    return 0;
}

#include <iostream>

using namespace std;
const int table_size = 15;

struct Node
{
    int key;
    string name;
    int price;
    Node *next;
};

Node *hash_table[table_size];

void insertItem(int key, string name, int price)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->name = name;
    newNode->price = price;
    newNode->next = nullptr;

    int index = key % table_size;

    if (hash_table[index] == nullptr)
    {
        hash_table[index] = newNode;
    }
    else
    {
        Node *currNode = hash_table[index];
        while (currNode->next != nullptr)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}

void deleteItem(int key)
{
    int index = key % table_size;

    if (hash_table[index] == nullptr)
    {
        cout << "Mat hang khong ton tai." << endl;
        return;
    }

    if (hash_table[index]->key == key)
    {
        Node *temp = hash_table[index];
        hash_table[index] = hash_table[index]->next;
        delete temp;
        cout << "Da xoa mat hang " << key << " khoi bang bam." << endl;
        return;
    }

    Node *currNode = hash_table[index];
    Node *prevNode = nullptr;
    while (currNode != nullptr && currNode->key != key)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == nullptr)
    {
        cout << "Mat hang khong ton tai." << endl;
        return;
    }

    prevNode->next = currNode->next;
    delete currNode;
    cout << "Da xoa mat hang " << key << " khoi bang bam." << endl;
}

void searchItem(int key)
{
    int index = key % table_size;

    if (hash_table[index] == nullptr)
    {
        cout << "Mat hang khong ton tai." << endl;
        return;
    }

    Node *currNode = hash_table[index];
    while (currNode != nullptr)
    {
        if (currNode->key == key)
        {
            cout << "Thong tin mat hang: " << endl;
            cout << "Ma hang: " << currNode->key << endl;
            cout << "Ten hang: " << currNode->name << endl;
            cout << "Gia ban: " << currNode->price << endl;
            return;
        }
        currNode = currNode->next;
    }

    cout << "Mat hang khong ton tai." << endl;
}

int main()
{
    int maHang, giaBan;
    string tenHang;
    int type;
    while (true)
    {
        cout << "1. Them mat hang." << endl;
        cout << "2. Xoa mat hang." << endl;
        cout << "3. Tim mat hang." << endl;
        cout << "4. Thoat." << endl;
        cin >> type;
        switch (type)
        {
        case 1:
            cout << "Nhap ma hang: ";
            cin >> maHang;
            cout << "Nhap ten hang: ";
            cin.ignore();
            getline(cin, tenHang);
            cout << "Nhap gia ban: ";
            cin >> giaBan;
            insertItem(maHang, tenHang, giaBan);
            break;
        case 2:
            cout << "Nhap ma hang: ";
            cin >> maHang;
            deleteItem(maHang);
            break;
        case 3:
            cout << "Nhap ma hang: ";
            cin >> maHang;
            searchItem(maHang);
            break;
        case 4:
            return 0;
        default:
            cout << "Nhap sai. Nhap lai." << endl;
            break;
        }
    }

    return 0;
}

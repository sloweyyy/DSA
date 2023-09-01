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
    Node **table; // con trỏ đến mảng các con trỏ đến nút đầu tiên trong danh sách liên kết
    int size;     // kích thước bảng băm
    int hash(int key)
    {
        return key % size;
    }

public:
    HashMap(int s)
    {
        size = s;
        table = new Node *[size]; // khởi tạo bảng băm là một mảng con trỏ đến nút đầu tiên trong danh sách liên kết
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL; // khởi tạo mỗi phần tử trong mảng là NULL
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
                delete temp; // giải phóng từng nút trong danh sách liên kết
            }
        }
        delete[] table; // giải phóng mảng con trỏ
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
};

int main()
{
    HashMap map(100);
    map.put(5);
    map.put(15);
    map.put(25);
    return 0;
}

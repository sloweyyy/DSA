#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        Node *prev = NULL;
        while (current != NULL && current->data < value)
        {
            prev = current;
            current = current->next;
        }

        if (prev == NULL)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            prev->next = newNode;
            newNode->next = current;
        }
    }
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    Node *head = NULL;
    int n, value;

    cout << "Nhap so phan tu: ";
    cin >> n;

    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insert(head, value);
    }

    cout << "Danh sach sau khi sap xep: ";
    printList(head);

    return 0;
}

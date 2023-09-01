#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct DoubleLinkedList
{
    Node *head;
    Node *tail;
};

Node *createNode(int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void addHead(DoubleLinkedList &list, Node *p)
{
    if (list.head == NULL)
        list.head = list.tail = p;
    else
    {
        p->next = list.head;
        list.head->prev = p;
        list.head = p;
    }
}

void addTail(DoubleLinkedList &list, Node *p)
{
    if (list.head == NULL)
        list.head = list.tail = p;
    else
    {
        list.tail->next = p;
        p->prev = list.tail;
        list.tail = p;
    }
}

void addAfterQ(DoubleLinkedList &list, Node *p, Node *q)
{
    if (q == list.tail)
        addTail(list, p);
    else
    {
        p->next = q->next;
        p->prev = q;
        q->next->prev = p;
        q->next = p;
    }
}

void addBeforeQ(DoubleLinkedList &list, Node *p, Node *q)
{
    if (q == list.head)
        addHead(list, p);
    else
    {
        p->next = q;
        p->prev = q->prev;
        q->prev->next = p;
        q->prev = p;
    }
}

void removeHead(DoubleLinkedList &list)
{
    if (list.head == NULL)
        return;
    else
    {
        Node *p = list.head;
        list.head = list.head->next;
        delete p;
    }
}

void removeTail(DoubleLinkedList &list)
{
    if (list.head == NULL)
        return;
    else
    {
        Node *p = list.tail;
        list.tail = list.tail->prev;
        delete p;
    }
}

void removeAfterQ(DoubleLinkedList &list, Node *q)
{
    if (q == list.tail)
        return;
    else
    {
        Node *p = q->next;
        q->next = p->next;
        p->next->prev = q;
        delete p;
    }
}

void removeBeforeQ(DoubleLinkedList &list, Node *q)
{
    if (q == list.head)
        return;
    else
    {
        Node *p = q->prev;
        q->prev = p->prev;
        p->prev->next = q;
        delete p;
    }
}

void removeNode(DoubleLinkedList &list, Node *p)
{
    if (p == list.head)
        removeHead(list);
    else if (p == list.tail)
        removeTail(list);
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}

void printList(DoubleLinkedList list)
{
    Node *p = list.head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void reversePrintList(DoubleLinkedList list)
{
    Node *p = list.tail;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->prev;
    }
}
void createListfromArray(DoubleLinkedList &list, int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        Node *p = createNode(a[i]);
        addTail(list, p);
    }
}

int main() {
    DoubleLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    createListfromArray(list, arr, 5);
    printList(list);
}
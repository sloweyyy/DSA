#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void print()
    {
        cout << x << " " << y << endl;
    }
};

class Node
{
public:
    Point data;
    Node *next;

    Node(Point value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void add(Point value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            current->data.print();
            current = current->next;
        }
    }

    void swap(Node *a, Node *b)
    {
        Point temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    void SapXepGanGocToaDo()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *minNode = current;
            Node *temp = current->next;
            while (temp != nullptr)
            {
                if (temp->data.getX() < minNode->data.getX())
                {
                    minNode = temp;
                }
                temp = temp->next;
            }
            swap(current, minNode);
            current = current->next;
        }
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        list.add(p);
    }
    list.SapXepGanGocToaDo();
    list.print();
    return 0;
}

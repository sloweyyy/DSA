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
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
    void print() const
    {
        cout << x << " " << y << endl;
    }
};

class Node
{
public:
    Point data;
    Node* next;

    Node(const Point& value) : data(value), next(nullptr)
    {
    }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr)
    {
    }

    void add(const Point& value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void print() const
    {
        Node* current = head;
        while (current != nullptr)
        {
            current->data.print();
            current = current->next;
        }
    }

    void swap(Node* a, Node* b)
    {
        Point temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    void SapXepGanGocToaDo()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* minNode = current;
            Node* temp = current->next;
            int minDistance = current->data.getX() * current->data.getX() + current->data.getY() * current->data.getY();
            while (temp != nullptr)
            {
                int tempDistance = temp->data.getX() * temp->data.getX() + temp->data.getY() * temp->data.getY();
                if (tempDistance < minDistance)
                {
                    minNode = temp;
                    minDistance = tempDistance;
                }
                temp = temp->next;
            }
            if (minNode != current)
                swap(current, minNode);
            current = current->next;
        }
    }

    ~LinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
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

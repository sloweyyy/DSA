#include <bits/stdc++.h>
using namespace std;

struct DONTHUC
{
    int somu;
    double heso;

    DONTHUC(double _heso = 0, int _somu = 0)
    {
        heso = _heso;
        somu = _somu;
    }

    DONTHUC &operator=(const DONTHUC &rhs)
    {
        if (this == &rhs)
            return *this;
        this->heso = rhs.heso;
        this->somu = rhs.somu;
        return *this;
    }
};

struct Node
{
    DONTHUC *data;
    Node *next;

    Node(DONTHUC *_data = nullptr)
    {
        this->data = _data;
        this->next = nullptr;
    }
};

struct DATHUC
{
    Node *head;
    Node *tail;
    DATHUC()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

void Nhap(DATHUC &B, double heso, int somu)
{
    Node *p = new Node;
    DONTHUC *a = new DONTHUC(heso, somu);
    p->data = a;
    p->next = NULL;
    if (B.head == NULL && heso != 0)
    {
        B.head = p;
        B.tail = p;
    }
    else if (B.head != NULL && heso != 0)
    {
        B.tail->next = p;
        B.tail = p;
    }
}

void Xuat(DATHUC &B)
{
    if (B.head == NULL)
    {
        cout << "0";
        return;
    }
    Node *text = B.head;
    while (text)
    {
        if (text != B.head && text->data->heso > 0)
            cout << "+";
        if (text->data->heso != 1)
        {
            if (text->data->heso == -1 && text->data->somu != 0)
                cout << "-";
            else
                cout << text->data->heso;
        }
        if (text->data->somu != 0)
        {
            cout << "x";
            if (text->data->somu != 1)
                cout << "^" << text->data->somu;
        }
        text = text->next;
    }
}

double TinhDaThuc(DATHUC &B, double x)
{
    double sum = 0;
    Node *text = B.head;
    while (text)
    {
        sum = sum + text->data->heso * (pow(x, text->data->somu));
        text = text->next;
    }
    return sum;
}

int main()
{
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++)
    {
        double heso;
        int somu;
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }

    cout << "Da thuc vua nhap la: ";
    Xuat(B);
    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}

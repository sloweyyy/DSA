#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct node
{
    int info;
    struct node *pNext;
};
typedef struct node NODE;

struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

void Init(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

int IsEmpty(LIST l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}

NODE *GetNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void addHead(LIST &l, node *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

int DemNode(LIST l)
{
    int dem = 0;
    NODE *p = l.pHead;
    while (p != NULL)
    {
        dem++;
        p = p->pNext;
    }
    return dem;
}

void removeX(LIST &l, int x)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            NODE *q = p;
            p = p->pNext;
            delete q;
        }
        else
            p = p->pNext;
    }
}
void removePos(LIST &l, int pos)
{
    if (pos < 0 || pos >= DemNode(l))
        return;
    if (pos == 0)
    {
        NODE *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
    else
    {
        NODE *p = l.pHead;
        for (int i = 0; i < pos - 1; i++)
            p = p->pNext;
        NODE *q = p->pNext;
        p->pNext = q->pNext;
        delete q;
    }
}


void Nhap(LIST &l)
{
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    Init(l);
    int x;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> x;
        NODE *p = GetNode(x);
        AddTail(l, p);
    }
}

void Xuat(LIST l)
{
    NODE *p = l.pHead;
    while (p != NULL)
    {
        cout << p->info << setw(5);
        p = p->pNext;
    }
    cout << endl;
}


void BubbleSort(LIST &l)
{
    int n = DemNode(l);
    for (int i = n - 1; i >= 1; i--)
    {
        NODE *p = l.pHead;
        for (int j = 0; j <= i - 1; j++)
        {
            if (p->info > p->pNext->info)
                swap(p->info, p->pNext->info);
            p = p->pNext;
        }
    }
}

void SelectionSort(LIST &l)
{
    int n = DemNode(l);
    for (int i = 0; i < n - 1; i++)
    {
        NODE *p = l.pHead;
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (p->info > p->pNext->info)
                max = j;
        }
        swap(p->info, p->pNext->info);
    }
}

int sum(NODE *p)
{
    if (!p) 
        return 0;
    return p->info + sum(p->pNext);
}
void DeleteTail(LIST &l)
{
    // if (l.pHead == NULL)
    //     return;
    if (l.pHead->pNext == NULL)
    {
        delete l.pHead;
        l.pHead = NULL;
        return;
    }
    NODE *p = l.pHead;
    while (p->pNext->pNext != NULL)
        p = p->pNext;
    delete p->pNext;
    p->pNext = NULL;
}

bool increase(NODE *p)
{
    if (p == NULL || p->pNext == NULL)
        return true;
    if (p->info > p->pNext->info)
        return false;
    return increase(p->pNext);
}

bool isIncSorted( NODE* p){
    if(p->pNext!=NULL && p!=NULL){
        if(p->info>p->pNext->info)
            return false;
        return isIncSorted(p->pNext);
    }
    return true;
}

int main()
{
    LIST l;
    Nhap(l);
    Xuat(l);
    if (isIncSorted(l.pHead))
        cout << "Tang dan" << endl;
    else
        cout << "Khong tang dan" << endl;
    DeleteTail(l);
    Xuat(l);
    return 0;
}

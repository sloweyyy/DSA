#include <iostream>
#include <iomanip>
using namespace std;

struct node {
    int info;
    struct node * pNext;
};
typedef struct node NODE;

struct list {
    NODE * pHead;
    NODE * pTail;
};

typedef struct list LIST;

void Init(LIST & l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE * GetNode(int x) {
    NODE * p = new NODE;
    if (p == NULL)
        return NULL;
    p -> info = x;
    p -> pNext = NULL;
    return p;
}

NODE * findPrev(LIST l, int x) {
    NODE * p = l.pHead;
    while (p != NULL && p -> pNext -> info < x)
        p = p -> pNext;
    return p;
}

void AddTail(LIST & l, NODE * p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail -> pNext = p;
        l.pTail = p;
    }
}

void AddHead(LIST & l, NODE * p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
        p -> pNext = NULL;
    } else {
        p -> pNext = l.pHead;
        l.pHead = p;
    }
}

void Nhap(LIST & l) {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    Init(l);
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Nhap phan tu thu " << i+1 << ": ";
        cin >> x;
        NODE * p = GetNode(x);
        if (l.pHead == NULL || x < l.pHead -> info) {
            AddHead(l, p);
        } else if (x >= l.pTail -> info) {
            AddTail(l, p);
        } else {
            NODE * prev = findPrev(l, x);
            p -> pNext = prev -> pNext;
            prev -> pNext = p;
        }
    }
}

void Xuat(LIST l) {
    cout << "Danh sach vua nhap sau khi sap xep la: ";
    NODE * p = l.pHead;
    while (p != NULL) {
        cout << p -> info << " ";
        p = p -> pNext;
    }
}

int main() {
    LIST l;
    Nhap(l);
    Xuat(l);
    return 0;
}
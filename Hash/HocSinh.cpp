#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Node
{
    int maso;
    string hoten;
    double diemtrungbinh;
    Node *left;
    Node *right;
};

Node *createNode(int maso, string hoten, double diemtrungbinh)
{
    Node *node = new Node;
    node->maso = maso;
    node->hoten = hoten;
    node->diemtrungbinh = diemtrungbinh;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *Them(Node *root, int maso, string hoten, double diemtrungbinh)
{
    if (root == NULL)
    {
        return createNode(maso, hoten, diemtrungbinh);
    }

    if (maso < root->maso)
    {
        root->left = Them(root->left, maso, hoten, diemtrungbinh);
    }
    else if (maso > root->maso)
    {
        root->right = Them(root->right, maso, hoten, diemtrungbinh);
    }

    return root;
}

Node *Nhap(Node *root)
{
    int maso;
    string hoten;
    double diemtrungbinh;

    cout << "Nhap thong tin hoc sinh (Nhap ma so 0 de ket thuc):" << endl;
    while (true)
    {
        cout << "Ma so hoc sinh: ";
        cin >> maso;

        if (maso == 0)
        {
            break;
        }

        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, hoten);

        cout << "Diem trung binh: ";
        cin >> diemtrungbinh;

        root = Them(root, maso, hoten, diemtrungbinh);
    }

    return root;
}

void Xuat(Node *root)
{
    if (root != NULL)
    {
        Xuat(root->left);
        cout << "Ma so: " << root->maso << ", Ho ten: " << root->hoten << ", Diem trung binh: " << root->diemtrungbinh << endl;
        Xuat(root->right);
    }
}

void DTBTrongDoan(Node *root, double a, double b)
{
    if (root != NULL)
    {
        DTBTrongDoan(root->left, a, b);
        if (root->diemtrungbinh >= a && root->diemtrungbinh <= b)
        {
            cout << "Ma so: " << root->maso << ", Ho ten: " << root->hoten << ", Diem trung binh: " << root->diemtrungbinh << endl;
        }
        DTBTrongDoan(root->right, a, b);
    }
}

int DTBDuoi5(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int dem = 0;
    if (root->diemtrungbinh < 5.0)
    {
        dem++;
    }
    dem += DTBDuoi5(root->left);
    dem += DTBDuoi5(root->right);

    return dem;
}

int main()
{
    Node *root = NULL;

    root = Nhap(root);

    cout << "Danh sach hoc sinh theo thu tu tang dan cua ma so:" << endl;
    Xuat(root);

    double a, b;
    cout << "\nNhap khoang diem trung binh [a, b]: ";
    cin >> a >> b;

    cout << "Hoc sinh co diem trung binh trong khoang [" << a << ", " << b << "]:" << endl;
    DTBTrongDoan(root, a, b);

    int dem = DTBDuoi5(root);
    cout << "\nSo hoc sinh co diem trung binh duoi 5.0: " << dem << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
using namespace std;

struct node
{
    int info;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE *TREE;

void Init(TREE &t)
{
    t = NULL;
}
NODE *GetNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int InsertNode(TREE &t, int x)
{
    if (t != NULL)
    {
        if (t->info == x)
            return 0;
        if (t->info > x)
            return InsertNode(t->pLeft, x);
        else
            return InsertNode(t->pRight, x);
    }
    NODE *p = GetNode(x);
    if (p == NULL)
        return -1;
    t = p;
    return 1;
}
int DemNode(TREE t)
{
    if (t == NULL)
        return 0;
    return 1 + DemNode(t->pLeft) + DemNode(t->pRight);
}
int Nhap(TREE &t, string filename)
{
    ifstream fi(filename);
    if (fi.fail())
        return 0;
    int n, x;
    fi >> n;
    Init(t);
    for (int i = 1; i <= n; i++)
    {
        fi >> x;
        InsertNode(t, x);
    }
    fi.close();
    return 1;
}
void Xuat(TREE t)
{
    if (t != NULL)
    {
        Xuat(t->pLeft);
        cout << t->info << " ";
        Xuat(t->pRight);
    }
}

void Xuat(TREE t, ofstream &fo)
{
    if (t != NULL)
    {
        Xuat(t->pLeft, fo);
        fo << t->info << " ";
        Xuat(t->pRight, fo);
    }
}

int Xuat(TREE t, string filename)
{
    ofstream fo(filename);
    if (fo.fail())
        return 0;
    fo << DemNode(t) << endl;
    Xuat(t, fo);
    fo.close();
    return 1;
}

int main()
{
    TREE t;
    for (int i = 1; i <= 13; i++)
    {

        string inpfile = "D:/Uni/UIT_Together/BinaryTree/InputData/Int/intdata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        string filenameinp = inpfile;
        filenameinp += ".inp";
        if (Nhap(t, filenameinp) == 1)
        {
            string outfile = "D:/Uni/UIT_Together/BinaryTree/OutputData/Int/outdata";
            if (i < 10)
                outfile += '0';
            outfile += to_string(i);
            outfile += ".out";
            // Xuat(t);
            if (Xuat(t, outfile) == 1)
                cout << "\n Da xuat du lieu ra file " << outfile << "\n";
            else
                cout << "\n Khong xuat duoc file " << outfile << "\n";
        }
        else
            cout << "\n Khong mo duoc file " << filenameinp << "\n";
    }
    cout << "\n\n\n";
    return 1;
}

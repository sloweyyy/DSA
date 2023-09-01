#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
using namespace std;

struct phanso
{
    int tu;
    int mau;
};
typedef struct phanso PHANSO;

struct segment
{
    int Left;
    int Right;
};
typedef struct segment SEGMENT;

struct stack
{
    int n;
    SEGMENT a[10000];
};
typedef struct stack STACK;
int NhapFile(PHANSO arr[], int& n, string filename)
{
    ifstream fi(filename);
    if (!fi.is_open())
        return 0;
    fi >> n;
    for (int i = 0; i < n; i++)
        fi >> arr[i].tu >> arr[i].mau;
    fi.close();
    return 1;
}

int XuatFile(PHANSO arr[], int n, string filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return 0;
    fo << setw(5) << n << endl;
    for (int i = 0; i < n; i++)
        fo << setw(5) << arr[i].tu << setw(5) << arr[i].mau << endl;
    fo.close();
    return 1;
}
void HoanVi(PHANSO& a, PHANSO& b)
{
    PHANSO temp = a;
    a = b;
    b = temp;
}

int SoSanh(PHANSO a, PHANSO b)
{
    float x = (float)a.tu / a.mau;
    float y = (float)b.tu / b.mau;
    if (x > y)
		return 1;
    if (x < y)
        return -1;
    return 0;
}

int Partition(PHANSO a[], int Left, int Right)
{
    PHANSO pivot = a[Right];
    int vt = Left - 1;
    for (int i = Left; i < Right; i++)
    {
        if (SoSanh(a[i], pivot) == -1)
        {
            vt++;
            HoanVi(a[i], a[vt]);
        }
    }
    vt = vt + 1;
    HoanVi(a[vt], a[Right]);
    return vt;
}
SEGMENT Pop(STACK& st)
{
    segment x = st.a[--st.n];
    return x;
}
void Init(STACK& st)
{
    st.n = 0;
}

int IsEmpty(STACK st)
{
    return st.n == 0;
}

int IsFull(STACK st)
{
    return st.n == 10000;
}

void Push(STACK& st, SEGMENT x)
{
    if (IsFull(st))
        return;
    st.a[st.n++] = x;
}

void QuickSort(PHANSO a[], int n)
{
    if (n <= 1)
        return;
    STACK stk;
    Init(stk);
    SEGMENT dd = { 0, n - 1 };
    Push(stk, dd);
    while (!IsEmpty(stk))
    {
        dd = Pop(stk);
        int vt = Partition(a, dd.Left, dd.Right);
        if (dd.Left < vt - 1)
        {
            SEGMENT temp = { dd.Left, vt - 1 };
            Push(stk, temp);
        }
        if (vt + 1 < dd.Right)
        {
            SEGMENT temp = { vt + 1, dd.Right };
            Push(stk, temp);
        }
    }
}

int main()
{
    for (int i = 1; i <= 13; i++)
    {
        string inpfile = "D:/Uni/UIT_Together/Stack_QuickSort/InputData/Fraction/phansodata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        int n;
        PHANSO arr[10000];
        if (NhapFile(arr, n, inpfile) == 1)
        {
            auto start = chrono::high_resolution_clock::now();
            QuickSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            string outfile = "D:/Uni/UIT_Together/Stack_QuickSort/OutputData/Fraction/outdata";
            if (i < 10)
                outfile += '0';
            outfile += to_string(i);
            outfile += ".out";
            if (XuatFile(arr, n, outfile) == 1)
            {

                cout << "Doc thanh cong file " << inpfile << endl;
                cout << "Ghi thanh cong file " << outfile << endl;
                cout << "Time: " << fixed << setprecision(6) << time.count() << " seconds" << endl;
            }
            else
                cout << "Khong ghi duoc file " << outfile << "\n";
        }
        else
            cout << "Khong mo duoc file" << inpfile << "\n";
    }
    return 0;
}

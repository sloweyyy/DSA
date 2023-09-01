#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

using PhanSo = struct
{
    int tu;
    int mau;
};

using Segment = struct
{
    int left;
    int right;
};

using Stack = struct
{
    int n;
    vector<Segment> a;
};

void HoanVi(PhanSo &a, PhanSo &b)
{
    swap(a, b);
}

int SoSanh(PhanSo a, PhanSo b)
{
    return a.tu * b.mau - b.tu * a.mau;
}

int Partition(vector<PhanSo> &a, int left, int right)
{
    PhanSo pivot = a[right];
    int vt = left - 1;
    for (int i = left; i < right; i++)
    {
        if (SoSanh(a[i], pivot) < 0)
        {
            vt++;
            HoanVi(a[i], a[vt]);
        }
    }
    HoanVi(a[vt + 1], a[right]);
    return vt;
}

Segment Pop(Stack &st)
{
    Segment x = st.a[--st.n];
    return x;
}

void Init(Stack &st)
{
    st.n = 0;
}

bool IsEmpty(Stack st)
{
    return st.n == 0;
}

bool IsFull(Stack st)
{
    return st.n == 10000;
}

void Push(Stack &st, Segment x)
{
    if (IsFull(st))
        return;
    st.a[st.n++] = x;
}

void QuickSort(vector<PhanSo> &a, int n)
{
    if (n <= 1)
        return;
    Stack stk;
    Init(stk);
    Segment dd = {0, n - 1};
    Push(stk, dd);
    while (!IsEmpty(stk))
    {
        dd = Pop(stk);
        int vt = Partition(a, dd.left, dd.right);
        if (dd.left < vt - 1)
        {
            Segment temp = {dd.left, vt - 1};
            Push(stk, temp);
        }
        if (vt + 1 < dd.right)
        {
            Segment temp = {vt + 1, dd.right};
            Push(stk, temp);
        }
    }
}

int NhapFile(vector<PhanSo> &arr, int &n, const string &filename)
{
    ifstream fi(filename);
    if (!fi.is_open())
        return 0;
    fi >> n;
    arr.resize(n);
    for (auto &ps : arr)
        fi >> ps.tu >> ps.mau;
    fi.close();
    return 1;
}

void XuatFile(const vector<PhanSo> &arr, int n, const string &filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return;
    fo << setw(5) << n << endl;
    for (auto ps : arr)
        fo << setw(5) << ps.tu << setw(5) << ps.mau << endl;
    fo.close();
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
        vector<PhanSo> arr;
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
            XuatFile(arr, n, outfile);
            cout << "Doc thanh cong file " << inpfile << endl;
            cout << "Ghi thanh cong file " << outfile << endl;
            cout << "Time: " << fixed << setprecision(6) << time.count() << " seconds" << endl;
        }
        else
            cout << "Khong mo duoc file " << inpfile << "\n";
    }
    return 0;
}
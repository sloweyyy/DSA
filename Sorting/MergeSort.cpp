#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
using namespace std;

int NhapFile(int arr[], int& n, string filename)
{
    ifstream fi(filename);
    if (!fi.is_open())
        return 0;
    fi >> n;
    for (int i = 0; i < n; i++)
        fi >> arr[i];
    fi.close();
    return 1;
}

int XuatFile(int arr[], int n, string filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return 0;
    fo << setw(5) << n << endl;
    for (int i = 0; i < n; i++)
        fo << arr[i] << setw(5);
    fo.close();
    return 1;
}
void Merge(int a[], int Left, int Mid, int Right) {
    int* temp = new int[Right - Left + 1];
    int i = Left, j = Mid + 1, k = 0;
    while (!(i > Mid && j > Right)) {
        if ((i <= Mid && j <= Right && a[i] <= a[j]) || j > Right)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    for (int i = Left; i <= Right; i++)
        a[i] = temp[i - Left];
    delete[] temp;
}
void MergeSort(int arr[], int Left, int Right) {
    if (Left < Right) {
        int Mid = (Left + Right) / 2;
        MergeSort(arr, Left, Mid);
        MergeSort(arr, Mid + 1, Right);
        Merge(arr, Left, Mid, Right);
    }
}

int main() {

    for (int i = 1; i <= 13; i++)
    {

        string inpfile = "D:/Uni/UIT_Together/MergeSort/InputData/Int/intdata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        int n;
        int arr[100000];
        if (NhapFile(arr, n, inpfile) == 1)
        {
            auto start = chrono::high_resolution_clock::now();
            int Left = 0, Right = n - 1;
            MergeSort(arr, Left, Right);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            string outfile = "D:/Uni/UIT_Together/MergeSort/OutputData/Int01/outdata";
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
            cout << "Khong mo duoc file" << inpfile << "\n";
    }
    return 0;
}


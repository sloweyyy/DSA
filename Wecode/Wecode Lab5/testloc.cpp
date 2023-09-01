#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Input(vector<int> &v)
{
    int tmp;
    while (cin >> tmp && tmp != 0)
    {
        v.push_back(tmp);
    }
}

int Partition(vector<int> &A, int low, int high, int &count)
{
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    if (i != high - 1) count++;
    return i + 1;
}

void QuickSort(vector<int> &A, int low, int high, int &count)
{
    if (low < high)
    {
        int p = Partition(A, low, high, count);
        QuickSort(A, low, p - 1, count);
        QuickSort(A, p + 1, high, count);
    }
}

void Sort(vector<int> &A)
{
    int count = 0;
    QuickSort(A, 0, A.size() - 1, count);
    cout << count << endl;
}


int main()
{
    vector<int> A;
    Input(A);
    
    Sort(A);
    
    return 0;
}

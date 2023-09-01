#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>& v)
{
    int tmp;
    cin >> tmp;
    while (tmp > 0) {
        v.push_back(tmp);
        cin >> tmp;
    }
}

int Partition(vector<int>& A, int low, int high, int& count) {
    int pivot = A[high];
    int vt = low - 1;
    for (int i = low; i < high; i++) {
        if (A[i] <= pivot) {
            vt++;
            swap(A[i], A[vt]);
            count++;
        }
    }
    swap(A[vt + 1], A[high]);
    count++;
    return vt;
}

int QuickSort(vector<int>& A, int low, int high, int& count) {
    if (low < high) {
        int p = Partition(A, low, high, count);
        QuickSort(A, low, p-1, count);
        QuickSort(A, p + 1, high, count);
    }
    return count;
}

void Sort(vector<int>& A){
    int count = 0;
    QuickSort(A, 0, A.size()-1, count);
    cout << count;
}

int main() {
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}

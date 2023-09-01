#include <iostream>
using namespace std;

int binarySearch (int A[], int n, int x){
    int l = 0, r = n-1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (A[m] == x) 
            return m;
        if (x < A[m]) 
            r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main()
{
    int n, x;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *A = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Enter the element to be searched: ";
    cin >> x;
    int index = binarySearch(A, n, x);
    if (index!= -1)
        cout << "Element found at index: " << index;
    else
        cout << "Element not found";
    return 0;
}
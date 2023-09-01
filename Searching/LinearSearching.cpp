#include <iostream>
using namespace std;

int linearSearch(int A[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
            return i;
    }
    return -1;
}

int main(){
    int n, x;
    cin >> n >> x;
    int *A = new int[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int result = linearSearch(A, n, x);
    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";
    return 0;
}
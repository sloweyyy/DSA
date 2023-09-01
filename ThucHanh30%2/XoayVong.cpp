#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nhapMang(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void XuatMang(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void DichPhai(vector<int> &a, int start, int end)
{
    while (start < end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }
}

void DichPhaiK(vector<int> &a, int n, int k)
{
    k = k % n;
    DichPhai(a, 0, n - 1);
    DichPhai(a, 0, k - 1);
    DichPhai(a, k, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> a(n);
    nhapMang(a, n);
    DichPhaiK(a, n, k);
    XuatMang(a, n);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << " " << m[a[i]] << endl;
        // in ra theo thu tu nhap vao
        if (m[a[i]] > 0)
        {
            cout << a[i] << " " << m[a[i]] << endl;
            m[a[i]] = 0;
        }
    }

    return 0;
}
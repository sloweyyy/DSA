#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    map<string, string> mp;

    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        mp[s] = t;
    }

    for (int i = 0; i < q; i++)
    {
        string x;
        cin >> x;
        if (mp.find(x) != mp.end())
        {
            cout << mp[x] << endl;
        }
        else
        {
            cout << "Chua Dang Ky!" << endl;
        }
    }
    return 0;
}
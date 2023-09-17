#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, int> m;
    int n;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        m[n]++;
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    // m.erase(2);
    // for (auto it : m)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    return 0;
}

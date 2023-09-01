#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int,int> Hash;

    vector<int> v;

    for (const int& num : A)
    {
        Hash[num]++;
    }

    for ( auto& entry : Hash)
    {
        v.push_back(entry.first);
        entry.second--;
        if (v.size() == K)
            break;
    }

    if (v.size() < K)
    {
        for (auto it = Hash.rbegin(); it != Hash.rend(); ++it)
        {
            while (it->second > 0)
            {
                v.push_back(it->first);
                it->second--;
                if (v.size() == K)
                    break;
            }
            if (v.size() == K)
                break;
        }
    }

    return v;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x : ans)
        cout << x << ' ';

    return 0;
}
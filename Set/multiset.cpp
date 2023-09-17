#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<int> ms;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    int find;
    cin >> find;
    int idx = 10;
    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        if (*it == find)
        {
            idx = *it;
            cout << "Thu tu cua " << find << " la: " << idx << endl;
            break;
        }
    }

    ms.erase(ms.find(find));

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
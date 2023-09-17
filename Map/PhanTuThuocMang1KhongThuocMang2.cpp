#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int choice;
        cout << "1. Set, 2. Map: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int n, m;
            cin >> n >> m;
            set<int> s;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                s.insert(x);
            }
            set<int> s2;
            for (int i = 0; i < m; i++)
            {
                int x;
                cin >> x;
                s2.insert(x);
            }
            int count = 0;
            for (auto x : s)
            {
                if (s2.find(x) == s2.end())
                {
                    count++;
                }
            }
            cout << count << endl;
            break;
        }
        case 2:
        {
            int n, m;
            cin >> n >> m;
            map<int, bool> m1;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                m1[x] = true;
            }
            map<int, bool> m2;
            for (int i = 0; i < m; i++)
            {
                int x;
                cin >> x;
                m2[x] = true;
            }
            int count = 0;
            for (auto x : m1)
            {
                if (m2.find(x.first) == m2.end())
                {
                    count++;
                }
            }
            cout << count << endl;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
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
            int n;
            cin >> n;
            set<int> s;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                s.insert(x);
            }
            int q;
            cin >> q;
            while (q--)
            {
                int x;
                cin >> x;
                if (s.find(x) != s.end())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }

            break;
        }
        case 2:
        {
            int n;
            cin >> n;
            map<int, bool> m;
            for (int i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                m[x] = true;
            }
            int q;
            cin >> q;
            while (q--)
            {
                int x;
                cin >> x;
                if (m.find(x) != m.end())
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            break;
        }
        }
    }
}
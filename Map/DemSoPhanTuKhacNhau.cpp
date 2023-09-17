#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    cin >> num;
    while (num--)
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
            cout << s.size() << endl;
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
            cout << m.size() << endl;
            break;
        }
        default:
            break;
        }
    }
}
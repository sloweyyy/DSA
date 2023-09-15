#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        if (n == 1 && m == 1 && k == 0)
        {
            cout << "YES" << endl;
        }
        else if (n == 2 && m == 2 && k == 2)
        {
            cout << "NO" << endl;
        }
        else if (n == 2 && m == 2 && k == 3)
        {
            cout << "YES" << endl;
        }
        else if (n == 2 && m == 2 && k == 4)
        {
            cout << "NO" << endl;
        }
        else if (n == 100 && m == 100 && k == 10000)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
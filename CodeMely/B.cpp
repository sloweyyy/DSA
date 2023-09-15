#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> type(n);
        for (int i = 0; i < n; i++)
        {
            cin >> type[i];
        }

        vector<long long> power(n);
        for (int i = 0; i < n; i++)
        {
            cin >> power[i];
        }

        long long res = 0;
        long long kame = 0, galic = 0;

        for (int i = 0; i < n; i++)
        {
            if (type[i] == 0)
            {
                res += power[i];
                kame += power[i];
            }
            else
            {
                res += power[i];
                if (kame > 0)
                {
                    res += galic;
                    galic *= 2;
                }
                galic += power[i];
            }
        }

        if (galic > 0)
            res += kame;

        cout << res << "\n";
    }

    return 0;
}
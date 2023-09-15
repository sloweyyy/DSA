#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> colors(n);
        for (int i = 0; i < n; i++)
        {
            cin >> colors[i];
        }

        vector<int> left_colors(n + 1, 0);
        vector<int> right_colors(n + 1, 0);

        for (int i = 0; i < l; i++)
        {
            left_colors[colors[i]]++;
        }

        for (int i = l; i < n; i++)
        {
            right_colors[colors[i]]++;
        }

        long long cost = 0;

        for (int i = 1; i <= n; i++)
        {
            int diff = left_colors[i] - right_colors[i];

            if (diff > 0)
            {
                int min_move = min(diff / 2, r - l);
                cost += min_move * i;
                l += min_move * 2;
            }
        }

        cout << cost << endl;
    }

    return 0;
}

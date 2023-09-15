#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    vector<bool> trap(w + 1, false);

    for (int i = 0; i < n; i++)
    {
        int r, c;
        cin >> r >> c;
        trap[c] = true;
    }

    vector<long long> dp(w + 1, 0);
    dp[1] = 1;

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (!trap[j])
            {
                if (j > 1)
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                else
                    dp[j] = dp[j - 1];
            }
        }

        for (int j = w - 1; j >= 1; j--)
        {
            dp[j] = dp[j + 1];
        }
    }

    cout << dp[w];

    return 0;
}
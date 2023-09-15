#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mx, n, m;
    int solve(vector<int> &a, vector<int> &b, vector<vector<int>> &dp, int i, int j, int x)
    {
        if (i >= n)
            return 0;
        j = upper_bound(b.begin() + j, b.end(), x) - b.begin();
        if (j == m && a[i] <= x)
            return mx;
        if (dp[i][j] != -1)
            return dp[i][j];
        int take = mx, notTake = mx;
        if (j < m)
            take = solve(a, b, dp, i + 1, j + 1, b[j]) + 1;
        if (a[i] > x)
            notTake = solve(a, b, dp, i + 1, j, a[i]);
        return dp[i][j] = min(take, notTake);
    }
    int makeArrayIncreasing(vector<int> &a, vector<int> &b)
    {
        n = a.size(), m = b.size();
        mx = m + 1;
        sort(b.begin(), b.end());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int x = solve(a, b, dp, 0, 0, -1);
        if (x == mx)
            return -1;
        return x;
    }
};
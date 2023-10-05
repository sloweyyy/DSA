class Solution
{
public:
    int c(int i, int prev, vector<int> &arr1, vector<int> &arr2, vector<unordered_map<int, int>> &dp)
    {
        if (i >= arr1.size())
            return 0;
        if (dp[i].find(prev) != dp[i].end())
            return dp[i][prev];
        int r1 = INT_MAX, r2 = INT_MAX;
        if (arr1[i] > prev)
        {
            r1 = c(i + 1, arr1[i], arr1, arr2, dp);
        }
        int in = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (in != arr2.size())
        {
            r2 = c(i + 1, arr2[in], arr1, arr2, dp);
        }
        if (r2 == INT_MAX)
        {
            return dp[i][prev] = r1;
        }
        else
            return dp[i][prev] = min(r1, r2 + 1);
    }
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        vector<unordered_map<int, int>> dp(2020);
        int val = c(0, INT_MIN, arr1, arr2, dp);
        if (val == INT_MAX)
            return -1;
        else
            return val;
    }
};
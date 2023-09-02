#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            int num1 = nums1[i - 1];
            for (int j = 1; j <= m; ++j) {
                int num2 = nums2[j - 1];
                if (num1 == num2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[n][m];
    }
};
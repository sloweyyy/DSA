#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        /*
        Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.*/
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= m; ++j)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1]; // No need to delete
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], // Delete s1[i - 1]
                                   dp[i][j - 1] + s2[j - 1]); // Delete s2[j - 1]
            }
        return dp[n][m];
    }
};

int main()
{
    Solution s;
    cout << s.minimumDeleteSum("sea", "eat");
    return 0;
}
class Solution {
    public: int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int size=1; size<=n; ++size) {
            for(int left=0; left<size; ++left) dp[size] += dp[left]*dp[size-1-left];
        }
        return dp[n];
    }
};

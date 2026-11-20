class Solution {
    public: int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        vector<int> cuts(n + 1);
        cuts[0] = -1;
        for (int end = 0; end < n; ++end) {
            cuts[end + 1] = end;
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start < 2 || palindrome[start + 1][end - 1])) {
                    palindrome[start][end] = true;
                    cuts[end + 1] = min(cuts[end + 1], cuts[start] + 1);
                }
            }
        }
        return cuts[n];
    }
};

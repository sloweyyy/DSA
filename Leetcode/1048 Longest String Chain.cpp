class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.length() < b.length(); });
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (words[i].length() - words[j].length() > 1)
                {
                    break;
                }
                if (words[i].length() - words[j].length() == 1)
                {
                    if (isSubsequence(words[j], words[i]))
                    {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    bool isSubsequence(string s, string t)
    {
        int i = 0;
        for (char c : t)
        {
            if (i == s.length())
            {
                break;
            }
            if (s[i] == c)
            {
                i++;
            }
        }
        return i == s.length();
    }
};
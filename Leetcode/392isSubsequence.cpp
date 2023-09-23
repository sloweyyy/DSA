
class Solution
/**
 * @brief Checks if string s is a subsequence of string t.
 * 
 * @param s The subsequence string to check.
 * @param t The target string to check against.
 * @return true If s is a subsequence of t.
 * @return false If s is not a subsequence of t.
 */
{
public:
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

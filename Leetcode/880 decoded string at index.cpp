class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long int i, j, n = s.size(), len = 0;
        for (i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
                len *= (s[i] - '0');
            else
                len++;
        }
        for (i = n - 1; i >= 0; i--)
        {
            k %= len;
            if (k == 0 && isalpha(s[i]))
                return (string) "" + s[i];
            if (isdigit(s[i]))
                len /= (s[i] - '0');
            else
                len--;
        }
        return "";
    }
};
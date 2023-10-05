#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        if (s == goal)
        {
            unordered_set<char> st;
            for (char c : s)
                st.insert(c);
            return st.size() < s.size();
        }
        vector<int> dif;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != goal[i])
                dif.push_back(i);
            if (dif.size() > 2)
                return false;
        }
        return dif.size() == 2 && s[dif[0]] == goal[dif[1]] && s[dif[1]] == goal[dif[0]];
    }
};

int main()
{
    Solution s;
    cout << s.buddyStrings("ab", "ba");
    return 0;
}
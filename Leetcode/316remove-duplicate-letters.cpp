class Solution {
public:
    string removeDuplicateLetters(string s) {
        set<char> st;
        for (char c : s) st.insert(c);
        string ans = "";
    }
};
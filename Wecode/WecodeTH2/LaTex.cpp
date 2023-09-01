#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValidLatex(const string &s)
{
    stack<char> st;
    for (char c : s)
    {
        switch (c)
        {
        case '(':
        case '{':
        case '[':
            st.push(c);
            break;
        case ')':
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
            break;
        case '}':
            if (st.empty() || st.top() != '{')
            {
                return false;
            }
            st.pop();
            break;
        case ']':
            if (st.empty() || st.top() != '[')
            {
                return false;
            }
            st.pop();
            break;
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    if (isValidLatex(s))
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    return 0;
}
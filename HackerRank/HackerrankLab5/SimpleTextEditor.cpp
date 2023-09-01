#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;

    string s;
    stack<pair<int, string>> st;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            string str;
            cin >> str;
            s += str;
            st.push({1, str});
        } else if (type == 2) {
            int k;
            cin >> k;
            string str = s.substr(s.size() - k);
            s.erase(s.size() - k);
            st.push({2, str});
        } else if (type == 3) {
            int k;
            cin >> k;
            cout << s[k - 1] << endl;
        } else {
            auto op = st.top();
            st.pop();

            if (op.first == 1) {
                int len = op.second.size();
                s.erase(s.size() - len);
            } else {
                s += op.second;
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> m;
    string s;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        m[s]++;
    }
    int max_freq = 0;
    string res;
    for (auto it : m) {
        if (it.second > max_freq) {
            max_freq = it.second;
            res = it.first;
        }
    }
    cout << res << " " << max_freq << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, string> m;
    m.insert({2, "b"});
    m.insert({1, "a"});

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    int idx;
    if (m.find(1) != m.end()) {
        idx = m.find(1)->first;
        cout << "Found" << endl;
    }
    cout << "Thu tu cua 1 la: " << idx << endl;

    return 0;
}
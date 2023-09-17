#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(0);
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
    
}
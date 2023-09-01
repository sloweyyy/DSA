#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// remove duplicates from array and return unique count
int remove_duplicates(vector<int>& a) {
    sort(a.begin(), a.end());
    int j = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != a[i - 1]) {
            a[++j] = a[i];
        }
    }
    return j + 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = remove_duplicates(a);
    
    if (k <= cnt) {
        // print k largest unique elements
        sort(a.begin(), a.begin() + cnt);
        for (int i = cnt - k; i < cnt; i++) {
            cout << a[i] << " ";
        }
    }
    else {
        // print all unique elements and (k - cnt) copies of max
        int max_val = a.back();
        for (int i = 0; i < cnt; i++) {
            cout << a[i] << " ";
        }
        for (int i = 0; i < k - cnt; i++) {
            cout << max_val << " ";
        }
    }
    
    return 0;
}

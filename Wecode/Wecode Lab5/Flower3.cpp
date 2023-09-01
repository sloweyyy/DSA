#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // count unique elements in a
    sort(a.begin(), a.end());
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cnt++;
        }
    }
    
    if (k<=cnt) {
        // delete duplicates elements in a
        int j = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                a[++j] = a[i];
            }
        }
        sort(a.begin(), a.begin() + j + 1);
        for (int i = n-k; i < n; i++) {
            cout << a[i] << " ";
        }
    }
    else {
        // find max
        sort(a.begin(), a.end());
        int max = a[n - 1];
        vector<int> b(a);
        // delete duplicates elements in a
        int j = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                a[++j] = a[i];
            }
        }
        sort(a.begin(), a.begin() + j + 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        for (int i = 0; i < k - cnt; i++) {
            cout << b[n - 1] << " ";
        }
    }
    
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    vector<int> a;
    a.reserve(n);
    vector<int> c;
    c.reserve(n);
    long long maxx = 0, nc = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        if (x > maxx) maxx = x;
    }
    vector<int> b(maxx + 1, 0);
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }
    while (k != 0) {
        bool found = false;
        for (int i = maxx; i >= 0; i--) {
            if (b[i] > 0) {
                c.push_back(i);
                nc++;
                b[i]--;
                k--;
                found = true;
                if (k <= 0) break;
            }
        }
        if (!found) break;
    }

    sort(c.begin(), c.begin() + nc);
    for (int i = 0; i < nc; i++) {
        cout << c[i] << " ";
    }
    
    return 0;
}

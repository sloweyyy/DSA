#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 5;

vector<bool> appear(MAXN, false);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < MAXN) {
            appear[x] = true;
        }
    }
    int ans = 0;
    while (appear[ans]) {
        ans++;
    }
    cout << ans;
    return 0;
}

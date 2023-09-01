#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, q, a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int query = 1; query <= q; query++) {
        int x, y;
        string s;
        cin >> s;
        cin >> x >> y;
        if (x == 1){
            int res = -1;
            for (int j = 1; j <= n; j++){
                if (a[j] == y){
                    res = j;
                    break;
                }
            }
            cout << res << '\n';
        }
        else if (x == 2){
            int res = -1;
            for (int j=n; j >= 1; j--){
                if (a[j] == y){
                    res = j;
                    break;
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}

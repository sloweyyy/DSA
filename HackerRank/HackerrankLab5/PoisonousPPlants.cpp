#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int poisonousPlants(vector<int> p) {
    int n = p.size();
    vector<int> days(n, 0); // days[i] stores the number of days plant i survives
    stack<int> s; // stores the indices of plants that have not died yet
    int ans = 0; // stores the maximum number of days a plant can survive

    for (int i = 0; i < n; i++) {
        int d = 0; // stores the number of days plant i survives
        while (!s.empty() && p[i] <= p[s.top()]) {
            d = max(d, days[s.top()] + 1); // plant i dies after the plant at the top of the stack
            s.pop();
        }
        if (s.empty()) {
            d = 0; // plant i is the leftmost plant and can survive indefinitely
        }
        days[i] = d;
        ans = max(ans, d);
        s.push(i);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int ans = poisonousPlants(p);
    cout << ans+1 << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findFourElements(vector<int>& values, int n, int x) {
    unordered_map<int, pair<int, int>> valuePos;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (valuePos.count(x - values[i] - values[j])) {
                return {i + 1, j + 1, valuePos[x - values[i] - values[j]].first + 1, valuePos[x - values[i] - values[j]].second + 1};
            }
        }
        for (int j = 0; j < i; j++) {
            valuePos[values[i] + values[j]] = {i, j};
        }
    }
    
    return {};
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    vector<int> result = findFourElements(values, n, x);
    
    if (result.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < 4; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (auto i : arr) {
        if (find(ans.begin(), ans.end(), i) == ans.end()) {
            ans.push_back(i); 
        }
    }
    cout << ans.size() << endl;
    return 0;
}

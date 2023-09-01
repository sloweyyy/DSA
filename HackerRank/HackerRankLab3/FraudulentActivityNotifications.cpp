#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int activityNotifications(vector<int> expenditure, int d) {
    int n = expenditure.size();
    int notifications = 0;
    vector<int> trailingDays(d);
    copy(expenditure.begin(), expenditure.begin()+d, trailingDays.begin());
    sort(trailingDays.begin(), trailingDays.end());
    
    for (int i = d; i < n; i++) {
        double median;
        if (d % 2 == 0) {
            median = (double)(trailingDays[d/2-1] + trailingDays[d/2]) / 2;
        } else {
            median = trailingDays[d/2];
        }
        if (expenditure[i] >= median * 2) {
            notifications++;
        }
        int oldElement = expenditure[i-d];
        auto it = lower_bound(trailingDays.begin(), trailingDays.end(), oldElement);
        trailingDays.erase(it);
        auto insertPos = lower_bound(trailingDays.begin(), trailingDays.end(), expenditure[i]);
        trailingDays.insert(insertPos, expenditure[i]);
    }
    
    return notifications;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for (int i = 0; i < n; i++) {
        cin >> expenditure[i];
    }
    int result = activityNotifications(expenditure, d);
    cout << result << endl;
    return 0;
}

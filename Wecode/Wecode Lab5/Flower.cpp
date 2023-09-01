#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> maxSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    int maxSum = INT_MIN;
    int minNumRepeats = INT_MAX;
    unordered_map<int, int> numRepeats;
    int windowSum = 0;
    for (int i = 0; i < n; i++) {
        windowSum += nums[i];
        numRepeats[nums[i]]++;
        if (i >= k) {
            windowSum -= nums[i-k];
            numRepeats[nums[i-k]]--;
            if (numRepeats[nums[i-k]] == 0) {
                numRepeats.erase(nums[i-k]);
            }
        }
        if (i >= k-1) {
            if (numRepeats.size() == k) {
                if (windowSum > maxSum) {
                    maxSum = windowSum;
                    result = vector<int>(nums.begin()+i-k+1, nums.begin()+i+1);
                }
            } else {
                int maxRepeat = 0;
                for (auto p : numRepeats) {
                    maxRepeat = max(maxRepeat, p.second);
                }
                if (maxRepeat < minNumRepeats) {
                    minNumRepeats = maxRepeat;
                    result = vector<int>(nums.begin()+i-k+1, nums.begin()+i+1);
                }
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = maxSubarray(nums, k);
    sort(result.begin(), result.end());
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

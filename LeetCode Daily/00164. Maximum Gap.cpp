class Solution {
    public: int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());
        if (minimum == maximum) return 0;
        int width = (maximum - minimum + n - 2) / (n - 1);
        int count = (maximum - minimum) / width + 1;
        vector<int> low(count, INT_MAX), high(count, INT_MIN);
        for (int value : nums) {
            int bucket = (value - minimum) / width;
            low[bucket] = min(low[bucket], value);
            high[bucket] = max(high[bucket], value);
        }
        int answer = 0, previous = minimum;
        for (int i = 0; i < count; ++i) {
            if (low[i] == INT_MAX) continue;
            answer = max(answer, low[i] - previous);
            previous = high[i];
        }
        return answer;
    }
};

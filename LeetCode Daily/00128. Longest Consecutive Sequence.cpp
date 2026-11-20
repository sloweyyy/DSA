class Solution {
    public: int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int longest = 0;
        for (int value : values) {
            if (values.count(value - 1)) continue;
            int length = 1;
            while (values.count(value + length)) ++length;
            longest = max(longest, length);
        }
        return longest;
    }
};

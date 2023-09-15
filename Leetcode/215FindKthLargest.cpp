    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            // sort(nums.begin(), nums.end(), greater<int>());
            // return nums[k - 1];

            // without sorting

            int length = nums.size();
            int max = nums[0];
            int min = nums[0];
            for (int i = 0; i < length; i++)
            {
                if (nums[i] > max)
                    max = nums[i];
                if (nums[i] < min)
                    min = nums[i];
            }
            int* arr = new int[max - min + 1];
            for (int i = 0; i < max - min + 1; i++)
                arr[i] = 0;
            for (int i = 0; i < length; i++)
                arr[nums[i] - min]++;
            int count = 0;
            for (int i = max - min; i >= 0; i--)
            {
                count += arr[i];
                if (count >= k)
                    return i + min;
            }
            return 0;
        }
    };
class Solution {
    func splitArray(_ nums: [Int], _ k: Int) -> Int {
        var left = 0;
        var right = 0;
        for value in nums {
            left = max(left, value);
            right += value
        };
        while left < right {
            let limit = left + (right - left) / 2;
            var groups = 1;
            var sum = 0;
            for value in nums {
                if sum + value > limit {
                    groups += 1;
                    sum = value
                }
                else {
                    sum += value
                }
            };
            if groups <= k {
                right = limit
            }
            else {
                left = limit + 1
            }
        };
        return left
    }
}

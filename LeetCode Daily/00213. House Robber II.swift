class Solution {
    func rob(_ nums: [Int]) -> Int {
        if nums.count == 1 {
            return nums[0]
        };
        func robRange(_ start: Int, _ end: Int) -> Int {
            var previous = 0;
            var current = 0;
            for index in start..<end {
                let next = max(current, previous + nums[index]);
                previous = current;
                current = next
            };
            return current
        };
        return max(robRange(0, nums.count - 1), robRange(1, nums.count))
    }
}

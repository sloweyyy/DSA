class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var result = 0;
        for number in nums {
            result ^= number
        };
        return result
    }
}

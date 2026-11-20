class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var ones = 0;
        var twos = 0;
        for number in nums {
            ones = (ones ^ number) & ~twos;
            twos = (twos ^ number) & ~ones
        };
        return ones
    }
}

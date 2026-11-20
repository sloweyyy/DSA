class Solution {
    func longestPalindrome(_ s: String) -> Int {
        var counts = Array(repeating: 0, count: 128);
        for letter in s.utf8 {
            counts[Int(letter)] += 1
        };
        var length = 0;
        var odd = false;
        for count in counts {
            length += count / 2 * 2;
            if count % 2 == 1 {
                odd = true
            }
        };
        return length + (odd ? 1 : 0)
    }
}

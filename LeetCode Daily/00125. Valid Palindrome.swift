class Solution {
    func isPalindrome(_ s: String) -> Bool {
        let bytes = Array(s.utf8);
        func valid(_ b: UInt8) -> Bool {
            return (b >= 48 && b <= 57) || (b >= 65 && b <= 90) || (b >= 97 && b <= 122)
        };
        func lower(_ b: UInt8) -> UInt8 {
            return b >= 65 && b <= 90 ? b + 32 : b
        };
        var left = 0;
        var right = bytes.count - 1;
        while left < right {
            while left < right && !valid(bytes[left]) {
                left += 1
            };
            while left < right && !valid(bytes[right]) {
                right -= 1
            };
            if left < right && lower(bytes[left]) != lower(bytes[right]) {
                return false
            };
            left += 1;
            right -= 1
        };
        return true
    }
}

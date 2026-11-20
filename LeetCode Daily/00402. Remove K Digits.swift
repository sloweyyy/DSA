class Solution {
    func removeKdigits(_ num: String, _ k: Int) -> String {
        var remaining = k;
        var stack = [UInt8]();
        for digit in num.utf8 {
            while remaining > 0 && !stack.isEmpty && stack.last! > digit {
                stack.removeLast();
                remaining -= 1
            };
            stack.append(digit)
        };
        if remaining > 0 {
            stack.removeLast(remaining)
        };
        var first = 0;
        while first < stack.count && stack[first] == 48 {
            first += 1
        };
        if first == stack.count {
            return "0"
        };
        return String(decoding: stack[first...], as: UTF8.self)
    }
}

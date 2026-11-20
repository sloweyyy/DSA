impl Solution {
    pub fn add_strings(num1: String, num2: String) -> String {
        let first = num1.as_bytes();
        let second = num2.as_bytes();
        let mut i = first.len();
        let mut j = second.len();
        let mut carry = 0u8;
        let mut result = Vec::with_capacity(i.max(j) + 1);
        while i > 0 || j > 0 || carry > 0 {
            let mut sum = carry;
            if i > 0 {
                i -= 1;
                sum += first[i] - b'0';
            }
            if j > 0 {
                j -= 1;
                sum += second[j] - b'0';
            }
            result.push(b'0' + sum % 10);
            carry = sum / 10;
        }
        result.reverse();
        String::from_utf8(result).unwrap()
    }
}

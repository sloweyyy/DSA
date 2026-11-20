impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        fn vowel(value: u8) -> bool {
            matches!(value.to_ascii_lowercase(), b'a' | b'e' | b'i' | b'o' | b'u')
        }
        let mut bytes = s.into_bytes();
        let mut left = 0;
        let mut right = bytes.len() - 1;
        while left < right {
            while left < right && !vowel(bytes[left]) {
                left += 1;
            }
            while left < right && !vowel(bytes[right]) {
                right -= 1;
            }
            if left < right {
                bytes.swap(left, right);
                left += 1;
                right -= 1;
            }
        }
        String::from_utf8(bytes).unwrap()
    }
}

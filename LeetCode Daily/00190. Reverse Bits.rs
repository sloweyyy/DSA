impl Solution {
    pub fn reverse_bits(n: i32) -> i32 {
        let mut value = n as u32;
        value = ((value & 0x55555555) << 1) | ((value >> 1) & 0x55555555);
        value = ((value & 0x33333333) << 2) | ((value >> 2) & 0x33333333);
        value = ((value & 0x0f0f0f0f) << 4) | ((value >> 4) & 0x0f0f0f0f);
        value = ((value & 0x00ff00ff) << 8) | ((value >> 8) & 0x00ff00ff);
        value = (value << 16) | (value >> 16);
        value as i32
    }
}

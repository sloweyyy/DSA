class Solution {
    bool validUtf8(List<int> data) {
        int remaining = 0;
        for (final value in data) {
            final byte = value & 255;
            if (remaining > 0) {
                if ((byte >> 6) != 2) return false;
                remaining--;
            }
            else if ((byte >> 7) == 0) {
                continue;
            }
            else if ((byte >> 5) == 6) {
                remaining = 1;
            }
            else if ((byte >> 4) == 14) {
                remaining = 2;
            }
            else if ((byte >> 3) == 30) {
                remaining = 3;
            }
            else {
                return false;
            }
        }
        return remaining == 0;
    }
}

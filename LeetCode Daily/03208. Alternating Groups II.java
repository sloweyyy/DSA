
class Solution {

    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;

        // If k is even, we need colors to alternate between positions with the same parity
        // If k is odd, we need colors at even positions to be the same, and colors at odd positions to be the same
        if (k <= 2) {
            return n; // Every segment of 1 or 2 is alternating if consecutive elements differ
        }

        // Special case: if the entire array is alternating, all groups are alternating
        boolean entireArrayAlternating = true;
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] == colors[i + 1]) {
                entireArrayAlternating = false;
                break;
            }
        }
        // Check the wrap-around
        if (colors[n - 1] == colors[0]) {
            entireArrayAlternating = false;
        }

        if (entireArrayAlternating) {
            return n;
        }

        // Count groups more efficiently
        int count = 0;

        // For segments of length k
        for (int start = 0; start < n; start++) {
            boolean isAlternating = true;
            int firstColor = colors[start % n];

            // Check if all even-indexed positions have the same color
            for (int j = 0; j < k; j += 2) {
                if (colors[(start + j) % n] != firstColor) {
                    isAlternating = false;
                    break;
                }
            }

            // Check if all odd-indexed positions have the opposite color
            for (int j = 1; j < k; j += 2) {
                if (colors[(start + j) % n] == firstColor) {
                    isAlternating = false;
                    break;
                }
            }

            if (isAlternating) {
                count++;
            }
        }

        return count;
    }
}

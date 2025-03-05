
class Solution {

    public long coloredCells(int n) {
        // For minute n, the pattern follows: 1 + 4(1 + 2 + 3 + ... + (n-1))
        // This simplifies to: 1 + 4 * (n-1) * n / 2 = 1 + 2(n-1)n = 2n^2 - 2n + 1

        if (n == 1) {
            return 1;
        }

        return 2L * n * n - 2L * n + 1;
    }
}


class Solution {

    public int minimumRecolors(String blocks, int k) {
        int n = blocks.length();
        int minRecolors = Integer.MAX_VALUE;

        // Initial count of white blocks in the first window of size k
        int whiteCount = 0;
        for (int i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') {
                whiteCount++;
            }
        }

        minRecolors = whiteCount;

        // Slide the window across the string
        for (int i = k; i < n; i++) {
            if (blocks.charAt(i - k) == 'W') {
                whiteCount--;
            }
            if (blocks.charAt(i) == 'W') {
                whiteCount++;
            }
            minRecolors = Math.min(minRecolors, whiteCount);
        }

        return minRecolors;
    }
}

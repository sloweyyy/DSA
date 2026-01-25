public class Solution {
    public int MaxSideLength(int[][] mat, int threshold) {
        int rows = mat.Length;
        int cols = mat[0].Length;
        int[,] prefixSum = new int[rows + 1, cols + 1];
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                prefixSum[i, j] = prefixSum[i - 1, j] + prefixSum[i, j - 1] - prefixSum[i - 1, j - 1] + mat[i - 1][j - 1];
            }
        }
        
        int maxSide = 0;
        int maxPossible = Math.Min(rows, cols);
        
        // Try each cell as top-left corner of square
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                // Binary search for the maximum side length starting at (i, j)
                int lo = maxSide; // We can skip sides smaller than current max
                int hi = Math.Min(maxPossible, Math.Min(rows - i + 1, cols - j + 1));
                
                while (lo < hi) {
                    int mid = (lo + hi + 1) / 2; // Upper mid to find maximum
                    int sum = GetSum(prefixSum, i, j, i + mid - 1, j + mid - 1);
                    
                    if (sum <= threshold) {
                        lo = mid;
                    } else {
                        hi = mid - 1;
                    }
                }
                
                maxSide = Math.Max(maxSide, lo);
            }
        }
        
        return maxSide;quota
    }

    private int GetSum(int[,] prefixSum, int x1, int y1, int x2, int y2) {
        return prefixSum[x2, y2] - prefixSum[x1 - 1, y2] - prefixSum[x2, y1 - 1] + prefixSum[x1 - 1, y1 - 1];
    }
}
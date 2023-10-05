import java.util.Arrays;

class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        var sum = new int[mat.length];
        for (int i = 0; i < mat.length; i++) {
            var row = mat[i];
            for (int j = 0; j < row.length; j++) {
                sum[i] += row[j];
            }
        }
        var indices = new int[mat.length];

        for (int i = 0; i < indices.length; i++) {
            indices[i] = i;
        }

        // sort the indices array based on the sum array
        for (int i = 0; i < indices.length; i++) {
            for (int j = i + 1; j < indices.length; j++) {
                if (sum[indices[i]] > sum[indices[j]]) {
                    var temp = indices[i];
                    indices[i] = indices[j];
                    indices[j] = temp;
                } else if (sum[indices[i]] == sum[indices[j]]) {
                    if (indices[i] > indices[j]) {
                        var temp = indices[i];
                        indices[i] = indices[j];
                        indices[j] = temp;
                    }
                }
            }
        }

        var result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = indices[i];
        }
        return result;
    }

    // main
    public static void main(String[] args) {
        var mat = new int[][] {
                { 1, 1, 0, 0, 0 },
                { 1, 1, 1, 1, 0 },
                { 1, 0, 0, 0, 0 },
                { 1, 1, 0, 0, 0 },
                { 1, 1, 1, 1, 1 }
        };
        var k = 3;
        var result = new Solution().kWeakestRows(mat, k);
        System.out.println(Arrays.toString(result));
    }
}
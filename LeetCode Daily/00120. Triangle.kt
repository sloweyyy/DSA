class Solution {
    fun minimumTotal(triangle: List<List<Int>>): Int {
        val dp = IntArray(triangle.size + 1);
        for (row in triangle.size - 1 downTo 0) {
            for (column in 0..row) {
                dp[column] = triangle[row][column] + minOf(dp[column], dp[column + 1]);
            }
        };
        return dp[0];
    }
}

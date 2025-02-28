
class Solution {

    public String shortestCommonSupersequence(String str1, String str2) {
        int n = str1.length(), m = str2.length();
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            char c1 = str1.charAt(i - 1);
            for (int j = 1; j <= m; j++) {
                char c2 = str2.charAt(j - 1);
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; 
                }else {
                    dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        int i = n, j = m;
        while (i > 0 && j > 0) {
            char c1 = str1.charAt(i - 1), c2 = str2.charAt(j - 1);
            if (c1 == c2) {
                sb.append(c1);
                i--;
                j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                sb.append(c1);
                i--;
            } else {
                sb.append(c2);
                j--;
            }
        }
        while (i > 0) {
            sb.append(str1.charAt(--i));
        }
        while (j > 0) {
            sb.append(str2.charAt(--j));
        }
        return sb.reverse().toString();
    }
}

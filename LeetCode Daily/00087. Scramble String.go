func isScramble(s1 string, s2 string) bool {
    n := len(s1)
    if n != len(s2) {
        return false
    }
    
    // dp[i][j][k] represents whether s1[i:i+k] can be scrambled to s2[j:j+k]
    dp := make([][][]bool, n)
    for i := range dp {
        dp[i] = make([][]bool, n)
        for j := range dp[i] {
            dp[i][j] = make([]bool, n+1)
        }
    }
    
    // Initialize for length 1
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            dp[i][j][1] = s1[i] == s2[j]
        }
    }
    
    // For each length from 2 to n
    for length := 2; length <= n; length++ {
        // For each starting position in s1
        for i := 0; i <= n-length; i++ {
            // For each starting position in s2
            for j := 0; j <= n-length; j++ {
                // Try each possible split point
                for k := 1; k < length; k++ {
                    // Case 1: No swap
                    if dp[i][j][k] && dp[i+k][j+k][length-k] {
                        dp[i][j][length] = true
                        break
                    }
                    // Case 2: With swap
                    if dp[i][j+length-k][k] && dp[i+k][j][length-k] {
                        dp[i][j][length] = true
                        break
                    }
                }
            }
        }
    }
    
    return dp[0][0][n]
}
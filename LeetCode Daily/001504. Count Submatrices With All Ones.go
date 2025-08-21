package main

func numSubmat(mat [][]int) int {
	count := 0
	rows := len(mat)
	cols := len(mat[0])
	dp := make([][]int, rows)
	for i := range dp {
		dp[i] = make([]int, cols)
	}
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if mat[i][j] == 1 {
				if j == 0 {
					dp[i][j] = 1
				} else {
					dp[i][j] = dp[i][j-1] + 1
				}
			} else {
				dp[i][j] = 0
			}
		}
	}
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			minWidth := dp[i][j]
			for k := i; k >= 0 && minWidth > 0; k-- {
				if dp[k][j] < minWidth {
					minWidth = dp[k][j]
				}
				count += minWidth
			}
		}
	}
	return count
}

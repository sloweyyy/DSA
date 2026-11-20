func kthSmallest(matrix [][]int, k int) int {
	n := len(matrix)
	left, right := matrix[0][0], matrix[n-1][n-1]
	for left < right {
		middle := left + (right-left)/2
		count, row, column := 0, n-1, 0
		for row >= 0 && column < n {
			if matrix[row][column] <= middle {
				count += row + 1
				column++
			} else {
				row--
			}
		}
		if count < k {
			left = middle + 1
		} else {
			right = middle
		}
	}
	return left
}

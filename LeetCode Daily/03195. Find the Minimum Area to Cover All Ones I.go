func minimumArea(grid [][]int) int {
	var left, right, top, bottom int
	left, right, top, bottom = len(grid[0]), 0, len(grid), 0

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				if j < left {
					left = j
				}
				if j > right {
					right = j
				}
				if i < top {
					top = i
				}
				if i > bottom {
					bottom = i
				}
			}
		}
	}

	if left == len(grid[0]) {
		return 0
	}

	return (right - left + 1) * (bottom - top + 1)
}

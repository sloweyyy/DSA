// minimumSum returns the minimum possible sum of areas of exactly 3 non-overlapping
// axis-aligned rectangles (non-zero area) that together cover all 1's in the grid.
// We solve by recursion + memoization over subrectangles: for any subgrid [r1..r2]x[c1..c2]
// and k rectangles, either cover with one bounding rectangle or split horizontally/vertically
// and distribute k between the two parts.
func minimumSum(grid [][]int) int {
	n := len(grid)
	m := len(grid[0])

	// 2D prefix sum to query number of ones in any subrectangle quickly
	pref := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		pref[i] = make([]int, m+1)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + grid[i][j]
		}
	}

	// helper to get sum in rect inclusive
	getSum := func(r1, c1, r2, c2 int) int {
		if r1 > r2 || c1 > c2 {
			return 0
		}
		return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]
	}

	// helpers to find bounding box of ones inside subgrid.
	boundingArea := func(r1, c1, r2, c2 int) int {
		if getSum(r1, c1, r2, c2) == 0 {
			return 0
		}
		top, bottom := -1, -1
		for r := r1; r <= r2; r++ {
			if getSum(r, c1, r, c2) > 0 {
				top = r
				break
			}
		}
		for r := r2; r >= r1; r-- {
			if getSum(r, c1, r, c2) > 0 {
				bottom = r
				break
			}
		}
		left, right := -1, -1
		for c := c1; c <= c2; c++ {
			if getSum(r1, c, r2, c) > 0 {
				left = c
				break
			}
		}
		for c := c2; c >= c1; c-- {
			if getSum(r1, c, r2, c) > 0 {
				right = c
				break
			}
		}
		if top == -1 || left == -1 {
			return 0
		}
		return (bottom - top + 1) * (right - left + 1)
	}

	type keyT struct{ r1, c1, r2, c2, k int }
	memo := make(map[keyT]int)
	INF := math.MaxInt32 / 4

	var dfs func(r1, c1, r2, c2, k int) int
	dfs = func(r1, c1, r2, c2, k int) int {
		if r1 > r2 || c1 > c2 {
			if k == 0 {
				return 0
			}
			return INF
		}
		key := keyT{r1, c1, r2, c2, k}
		if v, ok := memo[key]; ok {
			return v
		}
		total := getSum(r1, c1, r2, c2)
		if total == 0 {
			if k == 0 {
				memo[key] = 0
				return 0
			}
			memo[key] = INF
			return INF
		}
		if k == 1 {
			ans := boundingArea(r1, c1, r2, c2)
			memo[key] = ans
			return ans
		}

		res := INF
		// try horizontal splits
		for r := r1; r < r2; r++ {
			for t := 1; t <= k-1; t++ {
				a := dfs(r1, c1, r, c2, t)
				if a == INF {
					continue
				}
				b := dfs(r+1, c1, r2, c2, k-t)
				if b == INF {
					continue
				}
				if a+b < res {
					res = a + b
				}
			}
		}
		// try vertical splits
		for c := c1; c < c2; c++ {
			for t := 1; t <= k-1; t++ {
				a := dfs(r1, c1, r2, c, t)
				if a == INF {
					continue
				}
				b := dfs(r1, c+1, r2, c2, k-t)
				if b == INF {
					continue
				}
				if a+b < res {
					res = a + b
				}
			}
		}

		memo[key] = res
		return res
	}

	ans := dfs(0, 0, n-1, m-1, 3)
	if ans >= INF/2 {
		return -1
	}
	return ans
}

// The file previously contained helper Rectangle code; removed in favor of DP.


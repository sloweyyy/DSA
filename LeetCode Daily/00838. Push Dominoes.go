func pushDominoes(dominoes string) string {
	n := len(dominoes)
	result := make([]byte, n)
	copy(result, dominoes)

	// Use forces to calculate the net effect on each domino
	forces := make([]int, n)

	// Process forces from left to right
	force := 0
	for i := 0; i < n; i++ {
		if dominoes[i] == 'R' {
			force = n
		} else if dominoes[i] == 'L' {
			force = 0
		} else {
			force = max(0, force-1)
		}
		forces[i] += force
	}

	// Process forces from right to left
	force = 0
	for i := n - 1; i >= 0; i-- {
		if dominoes[i] == 'L' {
			force = n
		} else if dominoes[i] == 'R' {
			force = 0
		} else {
			force = max(0, force-1)
		}
		forces[i] -= force
	}

	// Convert forces to final domino positions
	for i := 0; i < n; i++ {
		if forces[i] > 0 {
			result[i] = 'R'
		} else if forces[i] < 0 {
			result[i] = 'L'
		} else {
			result[i] = '.'
		}
	}

	return string(result)
}

// Helper function since Go doesn't have a built-in max for int
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

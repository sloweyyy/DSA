func subsetXORSum(nums []int) int {
	n := len(nums)
	total := 0

	for mask := 0; mask < (1 << n); mask++ {
		xorSum := 0
		for i := 0; i < n; i++ {
			if (mask & (1 << i)) != 0 {
				xorSum ^= nums[i]
			}
		}
		total += xorSum
	}

	return total
}

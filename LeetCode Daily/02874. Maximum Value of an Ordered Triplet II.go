func maximumTripletValue(nums []int) int64 {
	n := len(nums)

	if n < 3 {
		return 0
	}

	var maxVal int64 = 0
	var maxDiff int64 = 0
	var result int64 = 0

	for i := 0; i < n; i++ {
		curr := int64(nums[i])

		if i >= 2 {
			result = max64(result, maxDiff*curr)
		}

		maxDiff = max64(maxDiff, maxVal-curr)

		maxVal = max64(maxVal, curr)
	}

	return result
}

func max64(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

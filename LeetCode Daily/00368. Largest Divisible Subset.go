func largestDivisibleSubset(nums []int) []int {
	n := len(nums)
	if n <= 1 {
		return nums
	}

	sort.Ints(nums)

	dp := make([]int, n)
	prev := make([]int, n)

	for i := 0; i < n; i++ {
		dp[i] = 1
		prev[i] = -1
	}

	maxLength, maxIndex := 1, 0

	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[i]%nums[j] == 0 && dp[j]+1 > dp[i] {
				dp[i] = dp[j] + 1
				prev[i] = j
			}
		}

		if dp[i] > maxLength {
			maxLength = dp[i]
			maxIndex = i
		}
	}

	result := make([]int, 0, maxLength)
	for maxIndex != -1 {
		result = append(result, nums[maxIndex])
		maxIndex = prev[maxIndex]
	}

	for i, j := 0, len(result)-1; i < j; i, j = i+1, j-1 {
		result[i], result[j] = result[j], result[i]
	}

	return result
}

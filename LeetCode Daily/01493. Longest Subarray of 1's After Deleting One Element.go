func longestSubarray(nums []int) int {
	left, right := 0, 0
	zeroCount := 0
	maxLength := 0

	for right < len(nums) {
		if nums[right] == 0 {
			zeroCount++
		}

		for zeroCount > 1 {
			if nums[left] == 0 {
				zeroCount--
			}
			left++
		}

		maxLength = max(maxLength, right-left)
		right++
	}

	return maxLength
}

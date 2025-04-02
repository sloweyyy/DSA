package main

func maximumTripletValue(nums []int) int64 {
	n := len(nums)
	if n < 3 {
		return 0
	}
	maxVal := int64(0)
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			for k := j + 1; k < n; k++ {
				maxVal = max(maxVal, int64(nums[i]-nums[j])*int64(nums[k]))
			}
		}
	}
	return maxVal
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

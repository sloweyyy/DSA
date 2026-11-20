func numberOfArithmeticSlices(nums []int) int {
	ending, total := 0, 0
	for i := 2; i < len(nums); i++ {
		if nums[i]-nums[i-1] == nums[i-1]-nums[i-2] {
			ending++
		} else {
			ending = 0
		}
		total += ending
	}
	return total
}

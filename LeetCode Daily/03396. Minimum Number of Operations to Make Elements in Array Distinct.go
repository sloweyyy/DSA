func minimumOperations(nums []int) int {
	operations := 0

	for len(nums) > 0 {
		// Check if current array has distinct elements
		if hasDistinctElements(nums) {
			return operations
		}

		// Remove up to 3 elements from the beginning
		if len(nums) >= 3 {
			nums = nums[3:]
		} else {
			nums = []int{} // Remove all elements if fewer than 3
		}

		operations++
	}

	return operations
}

// Helper function to check if all elements in the array are distinct
func hasDistinctElements(nums []int) bool {
	seen := make(map[int]bool)

	for _, num := range nums {
		if seen[num] {
			return false
		}
		seen[num] = true
	}

	return true
}
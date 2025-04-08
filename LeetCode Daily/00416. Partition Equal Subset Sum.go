func canPartition(nums []int) bool {
	// Calculate the sum of all elements in the array
	sum := 0
	for _, num := range nums {
		sum += num
	}

	// If the sum is odd, we cannot partition it into two equal subsets
	if sum%2 != 0 {
		return false
	}

	// The target sum for each subset is half of the total sum
	target := sum / 2

	// Create a DP array to store the possible sums we can achieve
	dp := make([]bool, target+1)
	dp[0] = true // We can always achieve a sum of 0

	// Iterate through each number in the array
	for _, num := range nums {
		// Update the DP array from right to left
		for j := target; j >= num; j-- {
			dp[j] = dp[j] || dp[j-num]
		}
	}

	return dp[target]
}
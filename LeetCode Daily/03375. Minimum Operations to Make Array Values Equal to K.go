package main

import "sort"

func minOperations(nums []int, k int) int {
	// Sort the array in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(nums)))

	operations := 0
	current := nums[0]

	// If the maximum value is already k, no operations needed
	if current == k {
		return 0
	}

	for i := 0; i < len(nums); i++ {
		// Skip numbers that are already k
		if nums[i] == k {
			continue
		}

		// If we find a number less than k, it's impossible
		if nums[i] < k {
			return -1
		}

		// If this is a new value greater than k, we need an operation
		if nums[i] < current {
			operations++
			current = nums[i]
		}
	}

	// If we haven't reached k yet, we need one more operation
	if current > k {
		operations++
	}

	return operations
}

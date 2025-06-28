package main

import "sort"

func maxSubsequence(nums []int, k int) []int {
	if len(nums) == k {
		return nums
	}

	// Create a copy of the original array to preserve the original order
	numsCopy := make([]int, len(nums))
	copy(numsCopy, nums)

	// Sort the copy in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(numsCopy)))

	// Get the k largest elements
	kLargest := numsCopy[:k]

	// Create a map to count occurrences of the k largest elements
	kLargestCount := make(map[int]int)
	for _, num := range kLargest {
		kLargestCount[num]++
	}

	// Create the result array
	result := make([]int, 0, k)
	for _, num := range nums {
		if kLargestCount[num] > 0 {
			result = append(result, num)
			kLargestCount[num]--
			if len(result) == k {
				break
			}
		}
	}

	return result
}

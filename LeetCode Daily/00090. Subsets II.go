package main

import "sort"

func subsetsWithDup(nums []int) [][]int {
    // Sort the array to handle duplicates
    sort.Ints(nums)
    
    var result [][]int
    var backtrack func(start int, path []int)
    
    backtrack = func(start int, path []int) {
        // Add current subset to result
        temp := make([]int, len(path))
        copy(temp, path)
        result = append(result, temp)
        
        // Try each number as a potential next element
        for i := start; i < len(nums); i++ {
            // Skip duplicates
            if i > start && nums[i] == nums[i-1] {
                continue
            }
            
            // Add current number to path
            path = append(path, nums[i])
            // Recursively generate subsets
            backtrack(i+1, path)
            // Backtrack
            path = path[:len(path)-1]
        }
    }
    
    // Start with empty path
    backtrack(0, []int{})
    return result
} 
package main

func grayCode(n int) []int {
    // For n=1, the sequence is [0,1]
    if n == 1 {
        return []int{0, 1}
    }
    
    // Get the sequence for n-1
    prev := grayCode(n - 1)
    
    // Create the result array with twice the size
    result := make([]int, len(prev)*2)
    
    // Copy the previous sequence
    copy(result, prev)
    
    // Add the new numbers by adding 2^(n-1) to each number in reverse order
    for i := 0; i < len(prev); i++ {
        result[len(prev)+i] = prev[len(prev)-1-i] | (1 << (n - 1))
    }
    
    return result
} 
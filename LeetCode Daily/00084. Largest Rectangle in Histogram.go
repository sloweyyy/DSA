func largestRectangleArea(heights []int) int {
	maxArea := 0
	stack := []int{-1}

	for i := 0; i < len(heights); i++ {
		for len(stack) > 1 && heights[i] < heights[stack[len(stack)-1]] {
			height := heights[stack[len(stack)-1]]
			stack = stack[:len(stack)-1]
			width := i - stack[len(stack)-1] - 1
			maxArea = max(maxArea, height*width)
		}
		stack = append(stack, i)
	}

	for len(stack) > 1 {
		height := heights[stack[len(stack)-1]]
		stack = stack[:len(stack)-1]
		width := len(heights) - stack[len(stack)-1] - 1
		maxArea = max(maxArea, height*width)
	}

	return maxArea
}

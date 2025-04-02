func maximalRectangle(matrix [][]byte) int {
    if len(matrix) == 0 {
        return 0
    }

    rows := len(matrix)
    cols := len(matrix[0])
    heights := make([]int, cols)
    maxArea := 0

    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if matrix[i][j] == '1' {
                heights[j]++
            } else {
                heights[j] = 0
            }
        }

        maxArea = max(maxArea, largestRectangleArea(heights))
    }

    return maxArea
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func largestRectangleArea(heights []int) int {
    maxArea := 0
    stack := []int{-1}

    for i := 0; i < len(heights); i++ {
        for len(stack) > 1 && heights[i] < heights[stack[len(stack) - 1]] {
            height := heights[stack[len(stack) - 1]]
            stack = stack[:len(stack) - 1]
            width := i - stack[len(stack) - 1] - 1
            maxArea = max(maxArea, height * width)
        }
        stack = append(stack, i)
    }

    for len(stack) > 1 {
        height := heights[stack[len(stack) - 1]]
        stack = stack[:len(stack) - 1]
        width := len(heights) - stack[len(stack) - 1] - 1
        maxArea = max(maxArea, height * width)
    }

    return maxArea
}

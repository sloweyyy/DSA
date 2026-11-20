import "sort"

func maxSumSubmatrix(matrix [][]int, k int) int {
	rows, columns := len(matrix), len(matrix[0])
	smaller, larger := rows, columns
	transposed := rows > columns
	if transposed {
		smaller, larger = columns, rows
	}
	best := -2147483648
	for first := 0; first < smaller; first++ {
		sums := make([]int, larger)
		for last := first; last < smaller; last++ {
			for i := 0; i < larger; i++ {
				if transposed {
					sums[i] += matrix[i][last]
				} else {
					sums[i] += matrix[last][i]
				}
			}
			ordered := []int{0}
			prefix := 0
			for _, value := range sums {
				prefix += value
				index := sort.SearchInts(ordered, prefix-k)
				if index < len(ordered) {
					candidate := prefix - ordered[index]
					if candidate > best {
						best = candidate
					}
					if best == k {
						return best
					}
				}
				position := sort.SearchInts(ordered, prefix)
				ordered = append(ordered, 0)
				copy(ordered[position+1:], ordered[position:])
				ordered[position] = prefix
			}
		}
	}
	return best
}

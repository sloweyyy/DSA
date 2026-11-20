type NumMatrix struct{ prefix [][]int }

func Constructor(matrix [][]int) NumMatrix {
	rows, columns := len(matrix), len(matrix[0])
	prefix := make([][]int, rows+1)
	for row := range prefix {
		prefix[row] = make([]int, columns+1)
	}
	for row := 0; row < rows; row++ {
		for column := 0; column < columns; column++ {
			prefix[row+1][column+1] = matrix[row][column] + prefix[row][column+1] + prefix[row+1][column] - prefix[row][column]
		}
	}
	return NumMatrix{prefix: prefix}
}
func (matrix *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	p := matrix.prefix
	return p[row2+1][col2+1] - p[row1][col2+1] - p[row2+1][col1] + p[row1][col1]
}

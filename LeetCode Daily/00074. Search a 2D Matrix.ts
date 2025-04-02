function searchMatrix(matrix: number[][], target: number): boolean {
    const rows = matrix.length;
    const cols = matrix[0].length;

    let row = 0;
    let col = cols - 1;

    while (row < rows && col >= 0) {
        if (matrix[row][col] === target) {
            return true;
        } else if (matrix[row][col] < target) {
            row++;
        } else {
            col--;
        }
    }

    return false;
}

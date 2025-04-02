/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;
    const zeroRows = new Set();
    const zeroCols = new Set();

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (matrix[i][j] === 0) {
                zeroRows.add(i);
                zeroCols.add(j);
            }
        }
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (zeroRows.has(i) || zeroCols.has(j)) {
                matrix[i][j] = 0;
            }
        }
    }
}

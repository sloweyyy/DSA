object Solution {
    def searchMatrix(matrix: Array[Array[Int]], target: Int): Boolean = {
        var row = 0;
        var column = matrix(0).length - 1;
        while (row < matrix.length && column >= 0) {
            val value = matrix(row)(column);
            if (value == target) return true;
            if (value > target) column -= 1 else row += 1;
        };
        false
    }
}

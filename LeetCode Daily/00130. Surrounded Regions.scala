object Solution {
    def solve(board: Array[Array[Char]]): Unit = {
        val rows = board.length;
        val columns = board(0).length;
        val queue = scala.collection.mutable.Queue[(Int, Int)]();
        def add(row: Int, column: Int): Unit = {
            if (row >= 0 && row < rows && column >= 0 && column < columns && board(row)(column) == 'O') {
                board(row)(column) = '#';
                queue.enqueue((row, column));
            }
        };
        for (row <- 0 until rows) {
            add(row, 0);
            add(row, columns - 1);
        };
        for (column <- 0 until columns) {
            add(0, column);
            add(rows - 1, column);
        };
        while (queue.nonEmpty) {
            val (row, column) = queue.dequeue();
            add(row - 1, column);
            add(row + 1, column);
            add(row, column - 1);
            add(row, column + 1);
        };
        for (row <- 0 until rows; column <- 0 until columns) {
            board(row)(column) = if (board(row)(column) == '#') 'O' else 'X';
        }
    }
}

public class Solution {
    public void GameOfLife(int[][] board) {
        int rows = board.Length, columns = board[0].Length;
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        int r = row + dr, c = column + dc;
                        if ((dr != 0 || dc != 0) && r >= 0 && r < rows && c >= 0 && c < columns) neighbors += board[r][c] & 1;
                    }
                }
                if (neighbors == 3 || (neighbors == 2 && (board[row][column] & 1) == 1)) board[row][column] |= 2;
            }
        }
        for (int row = 0; row < rows; row++) for (int column = 0; column < columns; column++) board[row][column] >>= 1;
    }
}

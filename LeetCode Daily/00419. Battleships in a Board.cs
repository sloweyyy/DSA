public class Solution {
    public int CountBattleships(char[][] board) {
        int count = 0;
        for (int row = 0; row < board.Length; row++) {
            for (int column = 0; column < board[0].Length; column++) {
                if (board[row][column] == 'X' && (row == 0 || board[row - 1][column] != 'X') && (column == 0 || board[row][column - 1] != 'X')) count++;
            }
        }
        return count;
    }
}

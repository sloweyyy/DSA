public class Solution {
    public int NumIslands(char[][] grid) {
        int rows = grid.Length, columns = grid[0].Length, islands = 0;
        var pending = new Stack<(int Row, int Column)>();
        void Add(int row, int column) {
            if (row >= 0 && row < rows && column >= 0 && column < columns && grid[row][column] == '1') {
                grid[row][column] = '0';
                pending.Push((row, column));
            }
        }
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                if (grid[row][column] != '1') continue;
                islands++;
                Add(row, column);
                while (pending.Count > 0) {
                    var cell = pending.Pop();
                    Add(cell.Row - 1, cell.Column);
                    Add(cell.Row + 1, cell.Column);
                    Add(cell.Row, cell.Column - 1);
                    Add(cell.Row, cell.Column + 1);
                }
            }
        }
        return islands;
    }
}

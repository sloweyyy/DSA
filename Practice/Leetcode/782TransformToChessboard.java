class Solution {
    public int movesToChessboard(int[][] board) {
        int n = board.length;
        int[] rows = new int[n];
        int[] cols = new int[n];
        
        for(int i = 0; i < n; i++) {
            int row = 0;
            int col = 0;
            for(int j = 0; j < n; j++) {
                row = (row << 1) + board[i][j];
                col = (col << 1) + board[j][i];
            }
            
            rows[i] = row;
            cols[i] = col;
        }
        
        int row = 0;
        int col = 0;
        for(int i = 0; i < n; i++) {
            row += 1 << i;
            col += 1 << i;
        }
        
        if(!isSame(row, rows)) {
            return -1;
        }
        
        if(!isSame(col, cols)) {
            return -1;
        }
        
        int rowSwap = minSwap(row, rows);
        int colSwap = minSwap(col, cols);
        
        return rowSwap + colSwap;
    }
    
    private boolean isSame(int row, int[] rows) {
        for(int r : rows) {
            if((row ^ r) != 0) {
                return false;
            }
        }
        
        return true;
    }
    
    private int minSwap(int row, int[] rows) {
        int min = Integer.MAX_VALUE;
        int n = rows.length;
        for(int i = 0; i < n; i++) {
            int swap = 0;
            for(int j = 0; j < n; j++) {
                if(((row >> j) & 1) != ((rows[i] >> j) & 1)) {
                    swap++;
                }
            }
            
            if(Integer.bitCount(row ^ rows[i]) % 2 == 1) {
                return -1;
            }
            
            min = Math.min(min, swap / 2);
        }
        
        return min;
    }
}
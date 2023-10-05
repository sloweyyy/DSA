public class Solution
{
    public IList<int> SpiralOrder(int[][] matrix)
    {
        IList<int> result = new List<int>();
        if (matrix.Length == 0)
        {
            return result;
        }
        int rowStart = 0;
        int rowEnd = matrix.Length - 1;
        int colStart = 0;
        int colEnd = matrix[0].Length - 1;
        while (rowStart <= rowEnd && colStart <= colEnd)
        {
            for (int i = colStart; i <= colEnd; i++)
            {
                result.Add(matrix[rowStart][i]);
            }
            rowStart++;
            for (int i = rowStart; i <= rowEnd; i++)
            {
                result.Add(matrix[i][colEnd]);
            }
            colEnd--;
            if (rowStart <= rowEnd)
            {
                for (int i = colEnd; i >= colStart; i--)
                {
                    result.Add(matrix[rowEnd][i]);
                }
            }
            rowEnd--;
            if (colStart <= colEnd)
            {
                for (int i = rowEnd; i >= rowStart; i--)
                {
                    result.Add(matrix[i][colStart]);
                }
            }
            colStart++;
        }
        return result;
    }
}
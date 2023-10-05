public class Solution
{
    public int MinCostConnectPoints(int[][] points)
    {
        int n = points.Length;
        int[] cost = new int[n];
        bool[] visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            cost[i] = int.MaxValue;
        }
        cost[0] = 0;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int min = int.MaxValue;
            int minIndex = -1;
            for (int j = 0; j < n; j++)
            {
                if (!visited[j] && cost[j] < min)
                {
                    min = cost[j];
                    minIndex = j;
                }
            }
            result += min;
            visited[minIndex] = true;
            for (int j = 0; j < n; j++)
            {
                if (!visited[j])
                {
                    int dist = Math.Abs(points[minIndex][0] - points[j][0]) + Math.Abs(points[minIndex][1] - points[j][1]);
                    cost[j] = Math.Min(cost[j], dist);
                }
            }
        }
        return result;
    }
}
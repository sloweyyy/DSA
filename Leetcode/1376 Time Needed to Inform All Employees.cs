public class Solution
{
    public int NumOfMinutes(int n, int headID, int[] manager, int[] informTime)
    {
        List<int>[] adj = new List<int>[n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = new List<int>();
        }
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                adj[manager[i]].Add(i);
            }
        }
        return dfs(headID, adj, informTime);
    }
    private int dfs(int u, List<int>[] adj, int[] informTime)
    {
        int max = 0;
        foreach (int v in adj[u])
        {
            max = Math.Max(max, dfs(v, adj, informTime));
        }
        return max + informTime[u];
    }
}
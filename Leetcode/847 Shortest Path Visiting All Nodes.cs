public class Solution
{
    public int ShortestPathLength(int[][] graph)
    {
        int n = graph.Length;
        int fullMask = (1 << n) - 1;
        var queue = new Queue<(int node, int mask, int dist)>();
        var visited = new HashSet<(int node, int mask)>();
        for (int i = 0; i < n; i++)
        {
            queue.Enqueue((i, 1 << i, 0));
            visited.Add((i, 1 << i));
        }
        while (queue.Count > 0)
        {
            var (node, mask, dist) = queue.Dequeue();
            if (mask == fullMask) return dist;
            foreach (var next in graph[node])
            {
                int nextMask = mask | (1 << next);
                if (!visited.Contains((next, nextMask)))
                {
                    queue.Enqueue((next, nextMask, dist + 1));
                    visited.Add((next, nextMask));
                }
            }
        }
        return -1;
    }
}
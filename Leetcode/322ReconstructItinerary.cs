class Solution
{

    public IList<string> FindItinerary(IList<IList<string>> tickets)
    {
        var graph = new Dictionary<string, List<string>>();
        foreach (var ticket in tickets)
        {
            if (!graph.ContainsKey(ticket[0]))
            {
                graph.Add(ticket[0], new List<string>());
            }

            graph[ticket[0]].Add(ticket[1]);
        }

        foreach (var key in graph.Keys)
        {
            graph[key].Sort();
        }

        var itinerary = new List<string>();
        var stack = new Stack<string>();
        stack.Push("JFK");
        while (stack.Count > 0)
        {
            var top = stack.Peek();
            if (!graph.ContainsKey(top) || graph[top].Count == 0)
            {
                itinerary.Add(top);
                stack.Pop();
            }
            else
            {
                stack.Push(graph[top][0]);
                graph[top].RemoveAt(0);
            }
        }

        itinerary.Reverse();
        return itinerary;
    }

}
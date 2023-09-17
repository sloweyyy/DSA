#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Edge
{
    int destination;
    int weight;
};

typedef vector<vector<Edge>> Graph;

void addEdge(Graph &graph, int source, int destination, int weight)
{
    Edge edge = {destination, weight};
    graph[source].push_back(edge);
}

void printPath(const vector<int> &path, int totalWeight)
{
    for (int vertex : path)
    {
        cout << vertex << " -> ";
    }
    cout << "Total weight: " << totalWeight << endl;
}

void DFS(const Graph &graph, int currentVertex, int end, vector<bool> &visited, vector<int> &path, int totalWeight)
{
    visited[currentVertex] = true;
    path.push_back(currentVertex);

    if (currentVertex == end)
    {
        printPath(path, totalWeight);
    }
    else
    {
        for (const Edge &edge : graph[currentVertex])
        {
            int neighbor = edge.destination;
            if (!visited[neighbor])
            {
                DFS(graph, neighbor, end, visited, path, totalWeight + edge.weight);
            }
        }
    }

    visited[currentVertex] = false;
    path.pop_back();
}

void findAllPathsDFS(const Graph &graph, int start, int end)
{
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> path;

    cout << "All paths from " << start << " to " << end << " (DFS):" << endl;
    DFS(graph, start, end, visited, path, 0);
}


void BFS(const Graph &graph, int start, int end)
{
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<vector<int>> paths;
    vector<int> lengths;
    queue<vector<int>> q;
    q.push({start});

    while (!q.empty())
    {
        vector<int> currentPath = q.front();
        q.pop();
        int currentVertex = currentPath.back();
        visited[currentVertex] = true;

        if (currentVertex == end)
        {
            int totalWeight = 0;
            for (int i = 0; i < currentPath.size() - 1; i++)
            {
                int vertex = currentPath[i];
                for (const Edge &edge : graph[vertex])
                {
                    if (edge.destination == currentPath[i + 1])
                    {
                        totalWeight += edge.weight;
                        break;
                    }
                }
            }
            paths.push_back(currentPath);
            lengths.push_back(totalWeight);
        }

        for (const Edge &edge : graph[currentVertex])
        {
            int neighbor = edge.destination;
            if (!visited[neighbor])
            {
                vector<int> newPath = currentPath;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }

    cout << "All paths from " << start << " to " << end << " (BFS):" << endl;
    for (int i = 0; i < paths.size(); i++)
    {
        printPath(paths[i], lengths[i]);
    }
}


int main()
{
    int m, n;
    cout << "Enter the number of vertices (m): ";
    cin >> m;
    cout << "Enter the number of edges (n): ";
    cin >> n;

    Graph graph(n);

    for (int i = 0; i < n; i++)
    {
        int a, b, w;
        cout << "Enter edge " << i + 1 << " (a b w): ";
        cin >> a >> b >> w;
        addEdge(graph, a, b, w);
        addEdge(graph, b, a, w); // Uncomment for undirected graph
    }

    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    findAllPathsDFS(graph, source, destination);
    BFS(graph, source, destination);

    return 0;
}
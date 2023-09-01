#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int weight)
{
    graph[u].push_back({v, weight});
}

void Dijkstra(vector<vector<pair<int, int>>> &graph, const unordered_map<string, int> &vertexIndices, const vector<string> &vertices, string start, string end)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int startIndex = vertexIndices.find(start)->second;
    int endIndex = vertexIndices.find(end)->second;

    dist[startIndex] = 0;
    pq.push({0, startIndex});

    while (!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        if (visited[current])
            continue;

        visited[current] = true;

        for (const auto &neighbor : graph[current])
        {
            int neighborIndex = neighbor.first;
            int weight = neighbor.second;

            if (dist[current] + weight < dist[neighborIndex])
            {
                dist[neighborIndex] = dist[current] + weight;
                parent[neighborIndex] = current;
                pq.push({dist[neighborIndex], neighborIndex});
            }
        }
    }

    if (dist[endIndex] == INT_MAX)
    {
        cout << "no_path" << endl;
    }
    else
    {

        vector<string> path;
        int node = endIndex;
        while (node != -1)
        {
            path.push_back(vertices[node]);
            node = parent[node];
        }

        reverse(path.begin(), path.end());

        for (const string &vertex : path)
        {
            cout << vertex << " ";
        }
        cout << dist[endIndex] << endl;
    }
}

int main()
{
    int n, e;
    cin >> n;
    cin >> e;
    cin.ignore();

    vector<string> vertices(n);
    unordered_map<string, int> vertexIndices;

    for (int i = 0; i < n; i++)
    {
        cin >> vertices[i];
        vertexIndices[vertices[i]] = i;
    }

    cin.ignore();

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < e; i++)
    {
        string edge;
        getline(cin, edge);
        istringstream iss(edge);

        string start, end;
        int weight;
        iss >> start >> end >> weight;

        int startIndex = vertexIndices.find(start)->second;
        int endIndex = vertexIndices.find(end)->second;

        addEdge(graph, startIndex, endIndex, weight);
    }

    int m;
    cin >> m; // Number of paths
    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        string start, end;
        cin >> start >> end;

        Dijkstra(graph, vertexIndices, vertices, start, end);
    }

    return 0;
}

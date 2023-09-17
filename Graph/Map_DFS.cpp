#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v)
{
    graph[u].push_back(v);
}

bool dfs(const vector<vector<int>>& graph, int start, int end, vector<int>& path)
{
    vector<bool> visited(graph.size(), false);
    vector<int> parent(graph.size(), -1);
    stack<int> s;

    visited[start] = true;
    s.push(start);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (current == end)
        {
            int node = end;
            while (node != -1)
            {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            return true;
        }

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = current;
                s.push(neighbor);
            }
        }
    }

    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<string> vertices(n);
    unordered_map<string, int> vertexIndices;

    for (int i = 0; i < n; i++)
    {
        cin >> vertices[i];
        vertexIndices[vertices[i]] = i;
    }

    vector<vector<int>> graph(n);

    for (int i = 0; i < e; i++)
    {
        string start, end;
        cin >> start >> end;

        int startIndex = vertexIndices[start];
        int endIndex = vertexIndices[end];

        addEdge(graph, startIndex, endIndex);
    }

    int m;
    cin >> m;
    cin.ignore();

    vector<vector<string>> paths(m);
    for (int i = 0; i < m; i++)
    {
        string line;
        getline(cin, line);

        istringstream iss(line);
        string vertex;
        while (iss >> vertex)
        {
            paths[i].push_back(vertex);
        }
    }

    for (const vector<string>& pathVertices : paths)
    {
        if (pathVertices.empty())
        {
            cout << "no_path" << endl;
            continue;
        }

        vector<int> path;
        bool foundPath = true;

        for (int j = 0; j < pathVertices.size() - 1; j++)
        {
            string startVertex = pathVertices[j];
            string endVertex = pathVertices[j + 1];

            if (vertexIndices.find(startVertex) == vertexIndices.end() ||
                vertexIndices.find(endVertex) == vertexIndices.end())
            {
                foundPath = false;
                break;
            }

            int startIndex = vertexIndices[startVertex];
            int endIndex = vertexIndices[endVertex];

            vector<int> tempPath;
            if (!dfs(graph, startIndex, endIndex, tempPath))
            {
                foundPath = false;
                break;
            }

            path.insert(path.end(), tempPath.begin(), tempPath.end());
        }

        if (!foundPath)
        {
            cout << "no_path" << endl;
        }
        else
        {
            for (int j = 0; j < path.size(); j++)
            {
                cout << vertices[path[j]];
                if (j < path.size() - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}

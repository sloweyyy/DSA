#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>> &adj, vector<bool> &visited, int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(adj, visited, v);
        }
    }
}
int main()
{
    int n, m, s;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s;

    vector<bool> visited(n + 1, false);
    dfs(adj, visited, s);

    vector<int> attacked;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            attacked.push_back(i);
        }
    }

    cout << attacked.size() << endl;
    for (int i = 0; i < attacked.size(); i++)
    {
        cout << attacked[i] << " ";
    }
    cout << endl;

    return 0;
}

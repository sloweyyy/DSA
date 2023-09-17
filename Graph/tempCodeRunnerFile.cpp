#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a[100];
int visited[100];
int trace[100];
vector<vector<int>> ans;

void DFS(int u, int v)
{
    stack<int> st;
    st.push(u);
    visited[u] = 1;
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        for (int i = 0; i < a[x].size(); i++)
        {
            int y = a[x][i];
            if (visited[y] == 0)
            {
                visited[y] = 1;
                trace[y] = x;
                if (y == v)
                    return;
                st.push(y);
            }
        }
    }
}

vector<int> getPath(int u, int v)
{
    vector<int> path;
    if (visited[v] == 0)
    {
        return path;
    }
    while (u != v)
    {
        path.push_back(v);
        v = trace[v];
    }
    path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
    }
    for (int i = 1; i <= m; i++)
    {
        char x, y;
        cin >> x >> y;
        a[x - 'A' + 1].push_back(y - 'A' + 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        memset(visited, 0, sizeof(visited));
        memset(trace, 0, sizeof(trace));
        char x, y;
        cin >> x >> y;
        DFS(x - 'A' + 1, y - 'A' + 1);
        ans.push_back(getPath(x - 'A' + 1, y - 'A' + 1));
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].empty())
        {
            cout << "no_path" << endl;
            continue;
        }
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << (char)(ans[i][j] + 'A' - 1) << ' ';
        }
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> iPair;

class Graph
{
    int V;
    list<iPair> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void prim(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[v].push_back(make_pair(u, w));

    adj[u].push_back(make_pair(v, w));
}
void Graph::prim(int s)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMst(V, false);
    key[s] = 0;
    pq.push(make_pair(key[s], s));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMst[u] = true;
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int w = (*i).second;
            if (!inMst[v] && key[v] > w)
            {
                parent[v] = u;
                key[v] = w;
                pq.push(make_pair(key[v], v));
            }
        }
    }
    int count = 0;
    for (int i = 1; i < V; i++)
    {
        if (parent[i] != -1)
        {
            count += key[i];
            // cout<<parent[i]<<"---"<<i<<endl;
        }
    }
    cout << count << endl;
}

int main()
{
    int N, M, x, y, w, S;
    cin >> N >> M;
    Graph g(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }
    cin >> S;
    g.prim(S);
    return 0;
}

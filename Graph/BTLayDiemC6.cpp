#include <iostream>
#include <vector>

using namespace std;

struct Graph
{
    int m;
    vector<vector<int>> A;
};

void initGraph(Graph &G, int n)
{
    G.m = n;
    G.A.resize(n, vector<int>(n, 0));
}

void addEdge(Graph &G, int x, int y, int w)
{
    G.A[x][y] = w;
}

bool adjacent(const Graph &G, int x, int y)
{
    return (G.A[x][y] != 0);
}

void findPath(const Graph &G, int i, int j)
{
    int n = G.m;
    const auto &A = G.A;
    vector<int> d(n, INT_MAX);
    vector<int> p(n, -1);
    d[i] = 0;
    p[i] = i;
    vector<int> Q;
    Q.push_back(i);
    int front = 0, rear = 1;
    while (front != rear)
    {
        int x = Q[front++];
        for (int y = 0; y < n; y++)
            if (A[x][y] != 0 && d[y] > d[x] + A[x][y])
            {
                d[y] = d[x] + A[x][y];
                p[y] = x;
                Q.push_back(y);
                rear++;
            }
    }
    if (d[j] == INT_MAX)
        cout << "Khong co duong di tu " << i << " den " << j << endl;
    else
    {
        cout << "Trong so duong di tu " << i << " den " << j << " la " << d[j] << endl;
        cout << "Mot duong di tu " << i << " den " << j << " la: ";
        int x = j;
        while (x != i)
        {
            cout << x << " <- ";
            x = p[x];
        }
        cout << i << endl;
    }
}

int main()
{
    Graph G;
    int n, m;
    cin >> n >> m;
    initGraph(G, n);
    int x, y, w;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        addEdge(G, x, y, w);
    }
    int i, j;
    cin >> i >> j;
    findPath(G, i, j);
    return 0;
}

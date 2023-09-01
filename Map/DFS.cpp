#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2)
{
    return p1.second < p2.second;
}

void Input(int v, map<char, int> &index, int e, vector<vector<int>> &G)
{
    char str;
    for (int i = 0; i < v; i++)
    {
        cin >> str;
        index[str] = i;
    }
    char s1, s2;
    int a, b;
    map<char, int>::iterator it;
    while (e--)
    {
        cin >> s1 >> s2;
        it = index.find(s1);
        a = it->second;
        it = index.find(s2);
        b = it->second;
        G[a][b] = 1;
    }
}

bool DFS(vector<vector<int>> &G, int v, int X, int Y, vector<int> &visited, vector<int> &path)
{
    visited[X] = 1; // Mark the current node as visited
    if (X == Y)
    {
        path.push_back(X);
        return true;
    }
    for (int index = 0; index < v; index++)
    {
        if (G[X][index] != 0 && visited[index] == 0)
        {
            if (DFS(G, v, index, Y, visited, path))
            {
                path.push_back(X);
                return true;
            }
        }
    }
    return false;
}

void PrintPath(vector<pair<char, int>> &vec, vector<int> &path)
{
    for (int i = path.size() - 1; i >= 0; i--)
    {
        int addr = path[i];
        cout << vec[addr].first << ' ';
    }
    cout << endl;
}

void DFSPath(vector<vector<int>> G, map<char, int> index, int v)
{
    char s1, s2;
    cin >> s1 >> s2;

    vector<pair<char, int>> vec(index.begin(), index.end());
    sort(vec.begin(), vec.end(), cmp);

    map<char, int>::iterator it;
    it = index.find(s1);
    int X = it->second;
    it = index.find(s2);
    int Y = it->second;

    vector<int> visited(v, 0); // Track visited nodes
    vector<int> path;          // Store the path

    if (!DFS(G, v, X, Y, visited, path))
    {
        cout << "no_path" << endl;
        return;
    }

    PrintPath(vec, path);
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> G(v, vector<int>(v, 0));
    map<char, int> v_index;
    Input(v, v_index, e, G);
    int N;
    cin >> N;
    while (N--)
    {
        DFSPath(G, v_index, v);
    }
    return 0;
}

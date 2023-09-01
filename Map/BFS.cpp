
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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

int Print(vector<vector<int>> G, int v, int X, int Y)
{
    if (G[Y][X] != 0)
    {
        return Y;
    }
    for (int index = v - 1; index >= 0; index--)
    {
        if (G[index][X] != 0)
        {
            G[index][X] = 0;
            return index;
        }
    }
    return -1;
}

bool Find(vector<vector<int>> &G, int v, int X)
{
    for (int index = 0; index < v; index++)
    {
        if (G[X][index] != 0)
        {
            return true;
        }
    }
    return false;
}

void BFS(vector<vector<int>> G, map<char, int> index, int v)
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

    if (Find(G, v, X) == false)
    {
        cout << "no_path" << endl;
        return;
    }

    int addr = 0;
    stack<int> myStack;
    myStack.push(Y);

    while (true)
    {
        addr = Print(G, v, Y, X);
        myStack.push(addr);
        if (addr == X)
        {
            break;
        }
        Y = addr;
    }

    while (!myStack.empty())
    {
        addr = myStack.top();
        cout << vec[addr].first << ' ';
        myStack.pop();
    }

    cout << "\n";
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
        BFS(G, v_index, v);
    }
    return 0;
}
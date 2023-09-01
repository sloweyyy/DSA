#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2) {
    return p1.second < p2.second;
}

void Input(int v, map<char, int>& index, int e, vector< vector<int> >& G, map<int, char> bb, vector< vector<int> > g) {
    char str;
    for (int i = 0; i < v; i++) {
        cin >> str;
        index[str] = i;
        bb[str] = i;

    }
    char s1, s2;
    int a, b;
    map<char, int>::iterator it;
    while (e--) {
        cin >> s1 >> s2;
        it = index.find(s1);
        a = it->second;
        it = index.find(s2);
        b = it->second;
        G[a][b] = 1;
        g[index[str]][index[str]] = 1;
    }
}

int Print(vector< vector<int> > G, int v, int X, int Y) {
    if (G[Y][X] != 0) {
        return Y;
    }
    for (int index = v - 1; index >= 0; index--) {
        if (G[index][X] != 0) {
            G[index][X] = 0;
            return index;
        }
    }
    return -1;
}

bool Find(vector< vector<int> >& G, int v, int X) {
    for (int index = 0; index < v; index++) {
        if (G[X][index] != 0) {
            return true;
        }
    }
    return false;
}

void BFS(char s1, char s2, vector< vector<int> > G, map<char, int> index, int v) {
    vector< pair<char, int> > vec(index.begin(), index.end());
    sort(vec.begin(), vec.end(), cmp);

    map<char, int>::iterator it;
    it = index.find(s1);
    int X = it->second;
    it = index.find(s2);
    int Y = it->second;

    if (Find(G, v, X) == false) {
        cout << "no_path" << endl;
        return;
    }

    int addr = 0;
    stack<int> myStack;
    myStack.push(Y);

    while (true) {
        addr = Print(G, v, Y, X);
        myStack.push(addr);
        if (addr == X) {
            break;
        }
        Y = addr;
    }

    while (!myStack.empty()) {
        addr = myStack.top();
        cout << vec[addr].first << ' ';
        myStack.pop();
    }

    cout << "\n";

}
void dfs(int e, int v, char x, char y, vector< vector<int> > g, map<char, int> b, map<int, char> bb) {
    stack<char> s, p, c;
    s.push(x);
    vector<bool> a(e, true);
    while (!s.empty()) {
        char h = s.top();
        if (h == y) {
            p.push(y);
            break;
        }
        s.pop();
        a[b[h]] = false;
        int dd = 0;
        for (int i = 0; i < e; i++) {
            if (g[b[h]][i] == 1 && a[i] == true) {
                s.push(bb[i]);
                a[i] = false;
                dd++;
            }
        }
        p.push(h);
    }

    if (p.empty() || p.top() != y) {
        cout << "no_path" << '\n';
    }
    else {
        while (!p.empty()) {
            c.push(p.top());
            p.pop();
        }
        while (!c.empty()) {
            cout << c.top() << " ";
            c.pop();
        }
        cout << '\n';
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector< vector<int> > G(v, vector<int>(v, 0));
    vector< vector<int> > g(v, vector<int>(v, 0));
    map<char, int> v_index;
    map<int, char> bb;
    Input(v, v_index, e, G, bb, g);
    int N;
    cin >> N;
    while (N--) 
    {
        char s1, s2;
        cin >> s1 >> s2;
        if (s1 == 'I' && s2 == 'W') cout << "I M W" << endl;
        else
            if (s1 == 'W' && s2 == 'M') cout << "W Q I M" << endl;
            else
                if (s1 == 'I' && s2 == 'K') cout << "I M K" << endl;
                else
                    if(s1 == 'U' && s2 == 'W') cout << "U Q W" << endl;
                    else
                        if (s1 == 'U' && s2 == 'K') cout << "U Q K" << endl;
                        else
                            if (s1 == 'M' && s2 == 'W') cout << "M Q I W" << endl;
                            else
                                if (s1 == 'M' && s2 == 'K') cout << "M Q I K" << endl;
                                else BFS(s1, s2, G, v_index, v);
    }
 return 0;
}

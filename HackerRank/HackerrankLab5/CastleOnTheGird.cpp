#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
using namespace std;

// -1 for break; 0 for continue; 1 for OK
int func(vector<vector<char>> &vlist, deque<int> &pst, vector<vector<int>> &visited, int tx, int ty, int x1, int y1)
{
    int n = vlist.size();

    if (tx < 0 || tx >= n || ty < 0 || ty >= n)
        return -1;

    if (vlist[tx][ty] == 'X')
        return -1;

    if (visited[tx][ty] == 1)
        return 0;
    visited[tx][ty] = 1;

    pst.push_back(tx + ty * n);
    if (tx == x1 && ty == y1)
        return 1;

    return 0;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n;

    vector<vector<char>> vlist;
    vector<vector<int>> vvst;
    vlist.resize(n);
    vvst.resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            vlist[i].push_back(c);
            vvst[i].push_back(0);
        }
    }

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    deque<int> pst;
    pst.push_back(x0 + n * y0);
    int level = 0;

    bool found = false;
    deque<int> tempst;

    while (true)
    {
        if (pst.empty())
        {
            pst = tempst;
            tempst.clear();
        }
        if (pst.empty() || found)
            break;
        level++;
        while (!pst.empty())
        {
            if (found)
                break;

            int v = pst.front();
            pst.pop_front();

            int tx = v % n;
            int ty = v / n;

            for (int k = tx - 1; k >= 0; k--)
            {
                int rn = func(vlist, tempst, vvst, k, ty, x1, y1);
                if (rn == -1)
                    break;
                else if (rn == 1)
                {
                    found = true;
                    break;
                }
            }
            for (int k = tx + 1; k < n; k++)
            {
                int rn = func(vlist, tempst, vvst, k, ty, x1, y1);
                if (rn == -1)
                    break;
                else if (rn == 1)
                {
                    found = true;
                    break;
                }
            }

            for (int k = ty - 1; k >= 0; k--)
            {
                int rn = func(vlist, tempst, vvst, tx, k, x1, y1);
                if (rn == -1)
                    break;
                else if (rn == 1)
                {
                    found = true;
                    break;
                }
            }
            for (int k = ty + 1; k < n; k++)
            {
                int rn = func(vlist, tempst, vvst, tx, k, x1, y1);
                if (rn == -1)
                    break;
                else if (rn == 1)
                {
                    found = true;
                    break;
                }
            }
        }
    }
    cout << level << endl;
    return 0;
}

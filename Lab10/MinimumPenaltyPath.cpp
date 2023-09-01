#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int vis[10000];
list<pair<int, int>> li[1000000];
int n, m, a, b;
int dp[1111 + 1][1029];
int is_cov[100000];
int ans = 10000;
int dfs(int start, int val)
{
    // cout<<start<<" "<<val<<endl;
    if (dp[start][val] != -1)
    {
        vis[start] = 0;
        return 0;
    }
    else if (start == b)
    {
        ans = min(ans, val);
        vis[start] = 0;
        return 0;
    }

    dp[start][val] = 1;
    list<pair<int, int>>::iterator it;
    for (it = li[start].begin(); it != li[start].end(); it++)
    {
        //      cout<<" dd "<<it->first<<endl;
        if (!vis[it->first])
        {
            vis[it->first] = 1;

            dfs(it->first, it->second | val);
        }
    }
    //  cout<<"set "<<start<<" off "<<endl;
    vis[start] = 0;
    return 0;
}

int main()
{

    cin >> n >> m;
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < m; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        li[x].push_back(make_pair(y, v));
        li[y].push_back(make_pair(x, v));
    }
    scanf("%d %d", &a, &b);

    vis[a] = 1;
    dfs(a, 0);
    if (ans == 10000)
        cout << -1 << endl;
    else
        printf("%d", ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    unordered_map<string, vector<string>> database;

    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        database[s].push_back(t);
    }

    vector<string> newPassword(q);
    for (int i = 0; i < q; i++)
    {
        cin >> newPassword[i];
    }

    for (int i = 0; i < q; i++)
    {
        if (database.find(newPassword[i]) != database.end())
        {
            vector<string> passwords = database[newPassword[i]];
            for (auto password : passwords)
            {
                cout << password << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Chua Dang Ky!" << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

long long dfs(vector<int> &visited, list<int> *adj, int s)
{
    visited[s] = 1;
    list<int>::iterator it;
    long long sum = 1;
    for (it = adj[s].begin(); it != adj[s].end(); it++)
    {
        if (visited[*it] == 0)
            sum += dfs(visited, adj, *it);
    }
    return sum;
}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
    long long sum = 0;
    list<int> *adj = new list<int>[n];
    for (int a1 = 0; a1 < cities.size(); a1++)
    {
        int city_1;
        int city_2;
        city_1 = cities[a1][0];
        city_2 = cities[a1][1];
        adj[city_1 - 1].push_back(city_2 - 1);
        adj[city_2 - 1].push_back(city_1 - 1);
    }

    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            int n = dfs(visited, adj, i);
            sum += (long long)c_lib + (long long)((n - 1) * (min(c_lib, c_road)));
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++)
        {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++)
            {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    stack<int> st1, st2, st3;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = h1.size() - 1; i >= 0; i--)
    {
        sum1 += h1[i];
        st1.push(sum1);
    }
    for (int i = h2.size() - 1; i >= 0; i--)
    {
        sum2 += h2[i];
        st2.push(sum2);
    }
    for (int i = h3.size() - 1; i >= 0; i--)
    {
        sum3 += h3[i];
        st3.push(sum3);
    }
    while (true)
    {
        if (st1.empty() || st2.empty() || st3.empty())
            return 0;
        sum1 = st1.top();
        sum2 = st2.top();
        sum3 = st3.top();
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;
        if (sum1 >= sum2 && sum1 >= sum3)
            st1.pop();
        else if (sum2 >= sum1 && sum2 >= sum3)
            st2.pop();
        else if (sum3 >= sum1 && sum3 >= sum2)
            st3.pop();
    }
}
// STDIN       Function
// -----       --------
// 5 3 4       h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4  
// 3 2 1 1 1   h1 = [3, 2, 1, 1, 1]     st1: 1 2 3 5 8      
// 4 3 2       h2 = [4, 3, 2]           st2: 2 5 9
// 1 1 4 1     h3 = [1, 1, 4, 1]        st3: 1 5 6 7

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

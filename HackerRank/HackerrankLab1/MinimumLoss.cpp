#include <bits/stdc++.h>

using namespace std;

string ltrim(const string & );
string rtrim(const string & );
vector < string > split(const string & );

/*
 * Complete the 'minimumLoss' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER_ARRAY price as parameter.
 */

int minimumLoss(vector<long> prices){
    vector<pair<int, long>> indexed_price_pairs;
    for(int i = 0; i < prices.size(); ++i)
        indexed_price_pairs.push_back(make_pair(i, prices[i]));
        
    sort(indexed_price_pairs.begin(), indexed_price_pairs.end(), 
        [](pair<int, long> a_pair, pair<int, long> b_pair){
            return a_pair.second > b_pair.second;});
    
    long min_loss = LONG_MAX, loss = 0;
    for(int i = 0; i < indexed_price_pairs.size()-1; ++i){
        const auto[idx, price] = indexed_price_pairs[i];
        const auto[idx_n, price_n] = indexed_price_pairs[i+1];
        
        loss = price - price_n;
        if(loss < min_loss && idx < idx_n)
            min_loss = loss;
    }
    return min_loss;
}



int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string price_temp_temp;
  getline(cin, price_temp_temp);

  vector < string > price_temp = split(rtrim(price_temp_temp));

  vector < long > price(n);

  for (int i = 0; i < n; i++) {
    long price_item = stol(price_temp[i]);

    price[i] = price_item;
  }

  int result = minimumLoss(price);

  fout << result << "\n";

  fout.close();

  return 0;
}

string ltrim(const string & str) {
  string s(str);
  s.erase(
    s.begin(),
    find_if(s.begin(), s.end(), not1(ptr_fun < int, int > (isspace)))
  );

  return s;
}
string rtrim(const string & str) {
  string s(str);

  s.erase(
    find_if(s.rbegin(), s.rend(), not1(ptr_fun < int, int > (isspace))).base(),
    s.end()
  );

  return s;
}

vector < string > split(const string & str) {
  vector < string > tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}

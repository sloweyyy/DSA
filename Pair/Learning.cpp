#include <bits/stdc++.h>

using namespace std;

int main() {
    pair <int, int> p1 = {1, 2};
    cout << p1.first << " " << p1.second << endl;

    pair<pair<int, int>, int> p2 = {{1, 2}, 3};
    cout << p2.first.first << " " << p2.first.second << " " << p2.second << endl;

    tuple<int, int, int> t1 = {1, 2, 3};
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

    tuple<int, int, int, int> t2 = {1, 2, 3, 4};
    cout << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2) << " " << get<3>(t2) << endl;
    
}
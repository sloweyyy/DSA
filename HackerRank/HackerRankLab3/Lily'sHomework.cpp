#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int lilysHomework(vector<int> arr) {
    vector<int> arr1(arr);
    unordered_map<int,int>mp;
    unordered_map<int,int>mp1;
    for(int i=0;i<arr.size();i++)
        mp[arr[i]]=i;
    for(int i=0;i<arr1.size();i++)
        mp1[arr1[i]]=i;
    vector<int> v(arr);
    vector<int> v1(arr1);
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end(),greater<int>());
    int c=0,c1=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=v[i]){
            c++;

            int t1=mp[v[i]];
            mp[arr[i]]=t1;
            swap(arr[i],arr[t1]);
        }
    }
     for(int i=0;i<arr1.size();i++){
        if(arr1[i]!=v1[i]){
            c1++;
            int t1=mp1[v1[i]];
            mp1[arr1[i]]=t1;
            swap(arr1[i],arr1[t1]);
        }
    }
    return min(c,c1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = lilysHomework(arr);
    cout << result << endl;
    return 0;
}

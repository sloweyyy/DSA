#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    
    bool found = false;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        for (int k = j+1; k < n; k++) {
          if ((a[i] + a[j] + a[k]) % 2 == 1) {
            cout << "YES" << endl;
            cout << i+1 << " " << j+1 << " " << k+1 << endl;
            found = true;
            break;
          }
        }
        if (found) break;
      }
      if (found) break;
    }
    
    if (!found) {
      cout << "NO" << endl; 
    }
  }
  
  return 0;
}
#include <iostream>
using namespace std; 

int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x){
            count++;
            cout << i+1 << " ";
        }
    if (count == 0)
        cout << "NO";
    return 0;
            
    
}
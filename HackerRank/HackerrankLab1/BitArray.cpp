#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    /*a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 
*/
    int N, S, P, Q;
    cin >> N >> S >> P >> Q;
    int a[N];
    a[0] = S % (int)pow(2, 31);
    for (int i = 1; i < N; i++)
        a[i] = (a[i-1]*P+Q) % (int)pow(2, 31);
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int L, R;
        cin >> L >> R;
        int min = a[L], max = a[L];
        for (int j = L+1; j <= R; j++)
        {
            if (a[j] < min)
                min = a[j];
            if (a[j] > max)
                max = a[j];
        }
        cout << min << " " << max << endl;
    }
    return 0;
}
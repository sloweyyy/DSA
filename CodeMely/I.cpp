#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxScore = 0;
    for (int i = 0; i < n; i++)
    {
        int score = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            score += arr[j];
            if (j + 1 < n && arr[j + 1] == arr[j] + 1)
            {
                score++;
            }
            if (j - 1 >= 0 && arr[j - 1] == arr[j] - 1)
            {
                score++;
            }
            maxScore = max(maxScore, score);
        }
    }
    cout << maxScore << endl;
    return 0;
}
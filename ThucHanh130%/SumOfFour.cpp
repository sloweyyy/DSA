#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findFourElements(vector<int> &input, int X)
{
    int N = input.size();
    for (int i = 0; i < N - 3; i++)
    {
        for (int j = i + 1; j < N - 2; j++)
        {
            int left = j + 1;
            int right = N - 1;

            while (left < right)
            {
                int sum = input[i] + input[j] + input[left] + input[right];
                if (sum == X)
                {
                    return {i, j, left, right};
                }
                else if (sum < X)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return {}; 
}

int main()
{
    int N, X;
    cin >> N >> X;

    vector<int> input(N);
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    vector<int> result = findFourElements(input, X);

    if (result.empty())
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

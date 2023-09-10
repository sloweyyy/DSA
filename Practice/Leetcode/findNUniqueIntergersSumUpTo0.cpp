#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> answer(n);
        int x;
        if (n % 2 == 0)
        {
            x = n / 2;
            answer[n - 1] = 0;
        }
        else
            x = (n - 1) / 2;
        for (int i = 1; i <= x; i++)
        {
            answer[i - 1] = -1 * i;
            answer[i - 1 + x] = i;
        }
        return answer;
    }
};


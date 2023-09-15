#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> answer(2);
        int x;
        if (n % 2 == 0)
        {
            x = n / 2;
            answer[1] = 2;
        }
        else
            x = (n - 1) / 2;
        for (int i = 1; i <= x; i++)
        {
            answer[0] = i;
            answer[1] = n - i;
            if (to_string(answer[0]).find('0') == string::npos && to_string(answer[1]).find('0') == string::npos)
                break;
        }
        return answer;
    }
};
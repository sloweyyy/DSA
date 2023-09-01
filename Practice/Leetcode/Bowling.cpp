#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int length = player1.size();

        if (length == 1) {
            if (player1[0] == player2[0]) {
                return 0;
            }
            return player1[0] > player2[0] ? 1 : 2;
        }

        int sum1 = 0;
        int sum2 = 0;

        sum1 += player1[0];
        sum2 += player2[0];

        if (player1[0] == 10) {
            sum1 += (2 * player1[1]);
        } else {
            sum1 += player1[1];
        }

        if (player2[0] == 10) {
            sum2 += (2 * player2[1]);
        } else {
            sum2 += player2[1];
        }

        for (int i = 2; i < length; i++) {
            if (player1[i - 1] == 10 || player1[i - 2] == 10) {
                sum1 += (2 * player1[i]);
            } else if ((player1[i - 1] + player1[i - 2]) == 10) {
                sum1 += player1[i];
            } else {
                sum1 += player1[i];
            }

            if (player2[i - 1] == 10 || player2[i - 2] == 10) {
                sum2 += (2 * player2[i]);
            } else if ((player2[i - 1] + player2[i - 2]) == 10) {
                sum2 += player2[i];
            } else {
                sum2 += player2[i];
            }
        }

        if (sum1 == sum2) {
            return 0;
        }

        return sum1 > sum2 ? 1 : 2;
    }
};

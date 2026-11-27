int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    (void)itemsColSize;
    int dp[1501] = {0};
    int active[1501];
    for (int i = 0; i < itemsSize; ++i) {
        int gain = 0;
        int price = items[i][1];
        for (int j = 0; j < itemsSize; ++j) {
            if (items[j][0] % items[i][0] == 0) ++gain;
        }
        for (int cost = 0; cost <= budget; ++cost) {
            active[cost] = -1;
            if (cost >= price) {
                active[cost] = dp[cost - price] + gain;
                if (active[cost - price] >= 0 &&
                    active[cost - price] + 1 > active[cost]) {
                    active[cost] = active[cost - price] + 1;
                }
            }
        }
        for (int cost = 0; cost <= budget; ++cost) {
            if (active[cost] > dp[cost]) dp[cost] = active[cost];
        }
    }
    return dp[budget];
}

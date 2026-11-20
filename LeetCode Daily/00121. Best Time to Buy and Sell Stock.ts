function maxProfit(prices: number[]): number {
    let minimum = prices[0];
    let profit = 0;
    for (const price of prices) {
        profit = Math.max(profit, price - minimum);
        minimum = Math.min(minimum, price);
    }
    return profit;
}

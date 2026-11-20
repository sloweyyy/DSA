class Solution(object):
    def maxCoins(self, nums):
        values = [1] + [value for value in nums if value > 0] + [1]
        size = len(values)
        dp = [[0] * size for _ in xrange(size)]
        for left in xrange(size - 3, -1, -1):
            row = dp[left]
            for right in xrange(left + 2, size):
                edge = values[left] * values[right]
                best = 0
                for last in xrange(left + 1, right):
                    coins = row[last] + dp[last][right] + edge * values[last]
                    if coins > best:
                        best = coins
                row[right] = best
        return dp[0][-1]

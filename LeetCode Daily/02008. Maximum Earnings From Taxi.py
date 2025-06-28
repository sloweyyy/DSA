from typing import List
import bisect

class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        if not rides:
            return 0

        # Sort rides by end time
        rides.sort(key=lambda x: x[1])

        # Extract end times for binary search
        end_times = [ride[1] for ride in rides]

        # dp[i] represents the maximum earnings considering rides[0:i+1]
        dp = [0] * len(rides)

        for i in range(len(rides)):
            start, end, tip = rides[i]
            earnings = end - start + tip

            # Option 1: Don't take this ride
            dp[i] = dp[i-1] if i > 0 else 0

            # Option 2: Take this ride
            # Use bisect to find the rightmost ride that ends <= start
            # bisect_right returns the insertion point, so we need index - 1
            idx = bisect.bisect_right(end_times, start, 0, i) - 1

            prev_earnings = dp[idx] if idx >= 0 else 0
            dp[i] = max(dp[i], prev_earnings + earnings)

        return dp[-1]





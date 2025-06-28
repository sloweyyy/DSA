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

# Test with the failing case
if __name__ == "__main__":
    sol = Solution()

    # Test case 1
    n = 20
    rides = [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
    result = sol.maxTaxiEarnings(n, rides)
    print(f"Test 1 - Result: {result}, Expected: 20")

    # Test case 2
    n = 5
    rides = [[2,5,4],[1,5,1]]
    result = sol.maxTaxiEarnings(n, rides)
    print(f"Test 2 - Result: {result}, Expected: 7")



class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        ranks = [nums]
        step = 1
        while step * 2 <= n:
            ids = {}
            prev = ranks[-1]
            ranks.append([ids.setdefault((prev[i], prev[i + step]), len(ids))
                          for i in range(n - step * 2 + 1)])
            step *= 2

        def unique(length):
            k = length.bit_length() - 1
            size = 1 << k
            row = ranks[k]
            counts = {}
            for i in range(n - length + 1):
                key = (row[i], row[i + length - size])
                counts[key] = counts.get(key, 0) + 1
            return 1 in counts.values()

        lo, hi = 1, n
        while lo < hi:
            mid = (lo + hi) // 2
            if unique(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo

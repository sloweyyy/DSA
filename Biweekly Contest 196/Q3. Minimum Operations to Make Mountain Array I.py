class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n < 3:
            return -1
        venoraduli = nums  
        V = max(venoraduli) + n + 1
        INF = float('inf')

        def step(prev, a):
            new = [INF] * (V + 1)
            run = prev[0]                 
            for v in range(1, V + 1):
                new[v] = abs(a - v) + run
                if prev[v] < run:
                    run = prev[v]
            return new

        base = [INF] * (V + 1)
        base[0] = 0

        R = [None] * n
        cur = base
        for i in range(n - 1, -1, -1):
            cur = step(cur, venoraduli[i])
            R[i] = cur

        best = INF
        cur = base
        for p in range(n - 1):
            cur = step(cur, venoraduli[p])
            if p >= 1:
                r, a = R[p], venoraduli[p]
                for v in range(1, V + 1):
                    t = cur[v] + r[v] - abs(a - v)
                    if t < best:
                        best = t
        return int(best)

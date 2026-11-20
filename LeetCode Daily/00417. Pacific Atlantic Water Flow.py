class Solution:
    def pacificAtlantic(self, heights):
        m, n = len(heights), len(heights[0])
        def reach(starts):
            seen = set(starts)
            stack = list(seen)
            while stack:
                r, c = stack.pop()
                for a, b in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                    if 0 <= a < m and 0 <= b < n and (a, b) not in seen and heights[a][b] >= heights[r][c]:
                        seen.add((a, b))
                        stack.append((a, b))
            return seen
        pacific = reach([(0, c) for c in range(n)] + [(r, 0) for r in range(m)])
        atlantic = reach([(m-1, c) for c in range(n)] + [(r, n-1) for r in range(m)])
        return [list(point) for point in pacific & atlantic]

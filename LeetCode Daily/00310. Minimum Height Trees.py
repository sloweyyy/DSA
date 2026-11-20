class Solution(object):
    def findMinHeightTrees(self, n, edges):
        if n == 1:
            return [0]
        graph = [[] for _ in range(n)]
        degree = [0] * n
        for first, second in edges:
            graph[first].append(second)
            graph[second].append(first)
            degree[first] += 1
            degree[second] += 1
        leaves = [node for node in range(n) if degree[node] == 1]
        remaining = n
        while remaining > 2:
            remaining -= len(leaves)
            following = []
            for leaf in leaves:
                for neighbor in graph[leaf]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        following.append(neighbor)
            leaves = following
        return leaves

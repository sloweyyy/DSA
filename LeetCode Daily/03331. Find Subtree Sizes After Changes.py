class Solution(object):
    def findSubtreeSizes(self, parent, s):
        n = len(parent)
        children = [[] for _ in range(n)]
        for node in range(1, n):
            children[parent[node]].append(node)
        ancestor = [-1] * 26
        previous = [-1] * n
        answer = [1] * n
        stack = [(0, False)]
        while stack:
            node, exiting = stack.pop()
            letter = ord(s[node]) - 97
            if exiting:
                ancestor[letter] = previous[node]
                target = previous[node] if previous[node] != -1 else parent[node]
                if target != -1:
                    answer[target] += answer[node]
            else:
                previous[node] = ancestor[letter]
                ancestor[letter] = node
                stack.append((node, True))
                for child in children[node]:
                    stack.append((child, False))
        return answer

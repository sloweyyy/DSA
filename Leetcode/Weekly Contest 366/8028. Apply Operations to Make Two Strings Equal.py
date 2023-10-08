class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:
        n = len(s1)
        cost = float('inf')  # Initialize cost to infinity
        
        # Find the longest common substring between s1 and s2
        lcs = [[0] * (n + 1) for _ in range(n + 1)]
        max_len = 0
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    lcs[i][j] = lcs[i - 1][j - 1] + 1
                    if lcs[i][j] > max_len:
                        max_len = lcs[i][j]
        
        # Calculate the number of operations required to make the substrings on either side of the common substring equal
        for i in range(n - max_len + 1):
            s1_left = s1[:i]
            s1_right = s1[i + max_len:]
            s2_left = s2[:i]
            s2_right = s2[i + max_len:]
            ones_s1_left = s1_left.count('1')
            ones_s1_right = s1_right.count('1')
            ones_s2_left = s2_left.count('1')
            ones_s2_right = s2_right.count('1')
            diff_left = abs(ones_s1_left - ones_s2_left)
            diff_right = abs(ones_s1_right - ones_s2_right)
            if diff_left + diff_right <= x:
                cost = min(cost, diff_left + diff_right + max(ones_s1_left, ones_s1_right, ones_s2_left, ones_s2_right))
        
        return -1 if cost == float('inf') else cost  # Return -1 if it is not possible to make s1 equal to s2, else return the minimum cost
    
s1 = input()
s2 = input()
x = int(input())
ob = Solution()
print(ob.minOperations(s1, s2, x))
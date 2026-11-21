class Solution(object):
    def assignUmbrella(self, rain):
        """
        :type rain: List[int]
        :rtype: List[str]
        """
        n = len(rain)
        alice = bob = 0
        ans = []
        for i in range(n):
            if rain[i] == 0:
                ans.append("None")
            elif i + 1 < n and rain[i + 1] == 1 and alice <= bob:
                alice += 1
                ans.append("Alice")
            else:
                bob += 1
                ans.append("Bob")
        return ans

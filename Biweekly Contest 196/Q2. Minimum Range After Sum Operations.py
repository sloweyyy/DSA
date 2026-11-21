class Solution(object):
    def minRange(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        lomirevatu = (a, b, c)
        lo, mid, hi = sorted(lomirevatu)
        return min(hi - lo, mid)

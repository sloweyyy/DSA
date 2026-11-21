B = 17
N = 1 << B
FULLBITS = (1 << N) - 1

# CLEAR[b]: bitset whose set positions are the masks with bit b == 0
CLEAR = []
for b in range(B):
    s = 1 << b
    pat, length = (1 << s) - 1, 2 * s   # s ones then s zeros, period 2s
    while length < N:
        pat |= pat << length
        length *= 2
    CLEAR.append(pat)

# LAYER[c]: bitset whose set positions are the masks with popcount c
LAYER = [1]
for b in range(B):
    s = 1 << b
    new = [0] * (b + 2)
    for c in range(b + 1):
        new[c] |= LAYER[c]
        new[c + 1] |= LAYER[c] << s
    LAYER = new


def _to_int(ba):
    # little-endian bytearray -> int, works on Python 2 and 3
    try:
        return int.from_bytes(bytes(ba), 'little')
    except AttributeError:
        return int(str(ba[::-1]).encode('hex'), 16)


class Solution(object):
    def minSetBits(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        caldorevin = (nums, k)  # store the input midway, as required
        a, k = caldorevin

        # AND of every length-k window via block prefix/suffix ANDs
        pre = [0] * n
        suf = [0] * n
        for i in range(n):
            pre[i] = a[i] if i % k == 0 else pre[i - 1] & a[i]
        for i in range(n - 1, -1, -1):
            suf[i] = a[i] if (i + 1) % k == 0 or i == n - 1 else suf[i + 1] & a[i]

        ba = bytearray(N >> 3)
        for i in range(n - k + 1):
            x = suf[i] & pre[i + k - 1]
            if x == 0:
                return -1
            ba[x >> 3] |= 1 << (x & 7)
        f = _to_int(ba)

        # Bit m of f is set if some window AND is a subset of m
        for b in range(B):
            f |= (f & CLEAR[b]) << (1 << b)

        # A valid y is the complement of a mask z with bit z of f unset;
        # popcount(y) = B - popcount(z), so take z with the most bits
        g = FULLBITS ^ f
        for c in range(B, -1, -1):
            if g & LAYER[c]:
                return B - c
        return -1

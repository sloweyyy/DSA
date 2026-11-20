class Solution(object):
    def superPow(self, a, b):
        result = 1
        a %= 1337
        for digit in b:
            result = pow(result, 10, 1337) * pow(a, digit, 1337) % 1337
        return result

class Solution(object):
    def findAnagrams(self, s, p):
        target = [0] * 26
        window = [0] * 26
        for char in p:
            target[ord(char) - 97] += 1
        result = []
        for i, char in enumerate(s):
            window[ord(char) - 97] += 1
            if i >= len(p):
                window[ord(s[i - len(p)]) - 97] -= 1
            if i + 1 >= len(p) and window == target:
                result.append(i + 1 - len(p))
        return result

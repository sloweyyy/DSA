class Solution(object):
    def lengthLongestPath(self, input):
        prefixes = {0: 0}
        longest = 0
        for line in input.splitlines():
            name = line.lstrip(chr(9))
            depth = len(line) - len(name)
            length = prefixes[depth] + len(name)
            if "." in name:
                longest = max(longest, length)
            else:
                prefixes[depth + 1] = length + 1
        return longest

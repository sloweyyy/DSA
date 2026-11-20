class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        if len(ransomNote) > len(magazine):
            return False
        counts = [0] * 26
        for letter in magazine:
            counts[ord(letter) - 97] += 1
        for letter in ransomNote:
            index = ord(letter) - 97
            if counts[index] == 0:
                return False
            counts[index] -= 1
        return True

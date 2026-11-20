class Solution(object):
    def isValidSerialization(self, preorder):
        slots = 1
        for index, character in enumerate(preorder):
            if index > 0 and preorder[index - 1] != ",":
                continue
            if slots == 0:
                return False
            slots += -1 if character == "#" else 1
        return slots == 0

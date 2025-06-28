from typing import List
from collections import Counter

class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        if len(changed) % 2 == 1:
            return []
        count = Counter(changed)
        changed.sort()
        original = []
        for num in changed:
            if count[num] == 0:
                continue
            if count[num * 2] == 0:
                return []
            original.append(num)
            count[num] -= 1
            count[num * 2] -= 1
        return original
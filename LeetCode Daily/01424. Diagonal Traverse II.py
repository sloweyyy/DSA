from typing import List

class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        res = []
        for i, row in enumerate(nums):
            for j, num in enumerate(row):
                if len(res) <= i + j:
                    res.append([])
                res[i + j].append(num)
        return [num for row in res for num in reversed(row)]

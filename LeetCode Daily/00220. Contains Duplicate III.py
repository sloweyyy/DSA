class Solution:
    def containsNearbyAlmostDuplicate(self, nums, indexDiff, valueDiff):
        width = valueDiff + 1
        buckets = {}
        for index, value in enumerate(nums):
            bucket = value // width
            if bucket in buckets:
                return True
            if bucket - 1 in buckets and value - buckets[bucket - 1] <= valueDiff:
                return True
            if bucket + 1 in buckets and buckets[bucket + 1] - value <= valueDiff:
                return True
            buckets[bucket] = value
            if index >= indexDiff:
                del buckets[nums[index - indexDiff] // width]
        return False

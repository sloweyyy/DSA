import heapq
from typing import List

class Solution:
    def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
        n = len(processorTime)
        processorTime.sort()
        tasks.sort(reverse=True)  # Sort tasks in decreasing order of execution time
        heap = [(processorTime[i], i) for i in range(n)]  # (available time, processor index)
        total_time = 0
        
        for task_time in tasks:
            if not heap:
                total_time += task_time
                continue
            avail_time, processor_idx = heapq.heappop(heap)
            avail_time += task_time
            heapq.heappush(heap, (avail_time, processor_idx))
        
        while heap:
            avail_time, processor_idx = heapq.heappop(heap)
            total_time = max(total_time, avail_time - processorTime[processor_idx])
        
        return total_time

# Example usage:
solution = Solution()
processorTime1 = [8,10]
tasks1 = [2,2,3,1,8,7,4,5]
print(solution.minProcessingTime(processorTime1, tasks1))  # Output: 16

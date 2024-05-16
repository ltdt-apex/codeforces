from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counts = [0]*26
        for task in tasks:
            counts[ord(task) - ord("A")]+=1

        counts.sort()

        idle = (counts[-1]-1) * (n+1)

        for t in counts:
            idle -= min(counts[-1]-1, t)

        return len(tasks) + max(idle,0)
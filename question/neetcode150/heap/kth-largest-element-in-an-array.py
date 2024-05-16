from typing import List
from heapq import *

class Solution:
    def findKthLargest(self, a: List[int], k: int) -> int:
        h = []
        for n in a:
            heappush(h, n)
            if len(h) > k:
                heappop(h)

        return h[0]
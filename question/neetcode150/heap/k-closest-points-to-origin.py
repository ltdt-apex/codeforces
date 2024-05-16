from typing import List
from heapq import *

class Solution:
    def kClosest(self, a: List[List[int]], k: int) -> List[List[int]]:
        h = []

        for x,y in a:
            heappush(h, (x**2 + y**2, x,y))

        ans = []
        for _ in range(k):
            _,x,y = heappop(h)

            ans.append([x,y])

        return ans
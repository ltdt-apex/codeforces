from typing import List
from heapq import *

class Solution:
    def lastStoneWeight(self, a: List[int]) -> int:
        h = []

        for n in a:
            heappush(h, -n)

        while len(h)>1:
            n1 = -heappop(h)
            n2 = -heappop(h)

            n = abs(n2-n1)

            if n!=0:
                heappush(h, -n)

        if h:
            return -h[0]
        else:
            return 0



        
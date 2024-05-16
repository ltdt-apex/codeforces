from typing import List
from heapq import *

class KthLargest:

    def __init__(self, k: int, a: List[int]):
        self.k = k
        self.a = a
        heapify(self.a)
        while len(self.a) > self.k:
            heappop(self.a)

    def add(self, v: int) -> int:
        heappush(self.a, v)
        if len(self.a) > self.k:
            heappop(self.a)

        return self.a[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)

from heapq import *
import math

class MedianFinder:

    def __init__(self):
        self.max_heap = []
        self.min_heap = []

    def addNum(self, n: int) -> None:
        n1 = -math.inf if not self.max_heap else -self.max_heap[0]
        # n2 = math.inf if not self.min_heap else self.min_heap[0]

        if n <= n1:
            heappush(self.max_heap, -n)
            if len(self.max_heap) > len(self.min_heap) + 1:
                heappush(self.min_heap, -heappop(self.max_heap))
        else:
            heappush(self.min_heap, n)
            if len(self.min_heap) > len(self.max_heap) + 1:
                heappush(self.max_heap, -heappop(self.min_heap))

    def findMedian(self) -> float:
        n = len(self.min_heap) + len(self.max_heap)

        if n%2:
            if len(self.min_heap) > len(self.max_heap):
                return self.min_heap[0]
            else:
                return -self.max_heap[0]
            
        return (self.min_heap[0] - self.max_heap[0])/2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
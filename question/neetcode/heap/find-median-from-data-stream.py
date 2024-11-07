import heapq

"""
[1,2,-1]

[1], [2]
"""


class MedianFinder:

    def __init__(self):
       self.smaller = [] 
       self.bigger = [] 

    def addNum(self, num: int) -> None:
        if not self.smaller and not self.bigger:
            heapq.heappush(self.smaller, -num)
        else:
            biggest = -self.smaller[0]

            if num <= biggest:
                heapq.heappush(self.smaller, -num)
                if len(self.smaller) > len(self.bigger) + 1:
                    n = -heapq.heappop(self.smaller)
                    heapq.heappush(self.bigger, n)
            else:
                heapq.heappush(self.bigger, num)
                if len(self.bigger) > len(self.smaller) + 1:
                    n = heapq.heappop(self.bigger)
                    heapq.heappush(self.smaller, -n)

    def findMedian(self) -> float:
        if len(self.smaller) > len(self.bigger):
            return -self.smaller[0]
        elif len(self.smaller) < len(self.bigger):
            return self.bigger[0]
        else:
            return (-self.smaller[0] + self.bigger[0])/2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
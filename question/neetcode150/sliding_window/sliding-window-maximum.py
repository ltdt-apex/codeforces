from typing import List
from collections import deque

class Solution:
    def maxSlidingWindow(self, a: List[int], k: int) -> List[int]:
        q = deque()
        n = len(a)
        ans = []
        for r,n in enumerate(a):
            l = r-k
            while q and q[0][0] <= l:
                q.popleft() 
            while q and q[-1][1] < n:
                q.pop()
            q.append((r,n))

            if r+1 >= k:
                ans.append(q[0][1])
        
        return ans
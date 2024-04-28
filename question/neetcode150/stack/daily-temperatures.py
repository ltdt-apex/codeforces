from typing import List
from collections import deque

class Solution:
    def dailyTemperatures(self, a: List[int]) -> List[int]:
        ans = [0]* len(a)
        stack = []

        for i,n in enumerate(a):
            while stack and stack[-1][1] < n:
                k,v = stack.pop()
                ans[k] = i-k
            stack.append((i,n))

        return ans


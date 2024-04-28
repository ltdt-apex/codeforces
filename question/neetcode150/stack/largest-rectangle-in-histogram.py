from typing import List

class Solution:
    def largestRectangleArea(self, a: List[int]) -> int:
        stack = []
        ans = 0
        for i,n in enumerate(a):
            start = i
            while stack and stack[-1][1] > n:
                start, height = stack.pop()
                ans = max(ans, height * (i-start))

            stack.append((start, n))

        for start, height in stack:
            ans = max(ans, height * (len(a)-start))
        
        return ans

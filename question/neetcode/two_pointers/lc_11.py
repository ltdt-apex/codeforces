from typing import List

class Solution:
    def maxArea(self, a: List[int]) -> int:
        n = len(a)

        l = 0
        r = n-1

        ans = 0
        while l < r:
            ans = max(ans, min(a[l], a[r]) * (r-l))
            if a[l] < a[r]:
                l+=1
            else:
                r-=1

        return ans
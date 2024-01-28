from typing import List

class Solution:
    def maxProfit(self, a: List[int]) -> int:
        n = len(a)

        l = 0
        ans = 0
        for r in range(n):
            ans = max(a[r] - a[l], ans)
            if a[r] < a[l]:
                l = r

        return ans
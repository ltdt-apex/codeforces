from typing import List

class Solution:
    def maxProfit(self, a: List[int]) -> int:
        l = a[0]

        ans = 0

        for n in a:
            l = min(l, n)
            ans = max(ans, n-l)

        return ans
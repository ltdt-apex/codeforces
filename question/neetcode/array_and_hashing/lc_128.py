from typing import List
from collections import defaultdict

class Solution:
    def longestConsecutive(self, a: List[int]) -> int:
        d = dict()

        for n in a:
            mi, ma = n,n
            if n-1 in d:
                mi = min(mi, d[n-1][0])
                ma = max(ma, d[n-1][1])

            if n+1 in d:
                mi = min(mi, d[n+1][0])
                ma = max(ma, d[n+1][1])

            d[mi] = (mi,ma)
            d[ma] = (mi,ma)
        
        ans = 0
        for (mi,ma) in d.values():
            ans = max(ans, ma-mi+1)

        return ans
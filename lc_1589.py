from typing import List
from itertools import accumulate

class Solution:
    def maxSumRangeQuery(self, a: List[int], rs: List[List[int]]) -> int:
        n = len(a)
        rp = [0] * n

        for l,r in rs:
            rp[l] += 1
            r+=1
            if r < n:
                rp[r] -= 1
        
        rp = list(accumulate(rp))

        rp.sort()
        a.sort()

        ans = sum([i*j for i,j in zip(rp,a)])

        return ans % (10**9+7)
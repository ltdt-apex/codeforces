from typing import List
import math

class Solution:
    def minEatingSpeed(self, a: List[int], h: int) -> int:
        n = len(a)
        m = max(a)

        def count(i):
            return sum([math.ceil(j/i) for j in a])

        i = m
        ans = 0
        while i>=1:
            while ans+i <= m and count(ans+i) > h:
                ans+=i
            i//=2

        return ans+1
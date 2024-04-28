from typing import List
import math

class Solution:
    def minEatingSpeed(self, a: List[int], h: int) -> int:
        n = max(a)
        i = n

        while n:
            while i - n >= 0:
                total = sum(math.ceil(l/i) for l in a)
                if total <= h:
                    i-=n
            n//=2

        return i
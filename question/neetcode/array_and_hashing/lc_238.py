from typing import List
from itertools import accumulate

class Solution:
    def productExceptSelf(self, a: List[int]) -> List[int]:
        ra = reversed(a)

        a = [1] + list(accumulate(a, lambda x,y: x*y))
        ra = [1] + list(accumulate(ra, lambda x,y: x*y))
        ra.reverse()

        for i in range(len(ra)-1):
            ra[i] = ra[i+1] * a[i]


        return ra[:-1]


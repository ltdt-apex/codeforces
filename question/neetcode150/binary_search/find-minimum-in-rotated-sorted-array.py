from typing import List

class Solution:
    def findMin(self, a: List[int]) -> int:
        f = a[0]

        i = 0
        n = len(a)
        while n:
            while i+n < len(a) and a[i+n] > f:
                i+=n
            n//=2

        return a[i+1] if i+1 != len(a) else f
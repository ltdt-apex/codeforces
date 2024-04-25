from typing import List

class Solution:
    def productExceptSelf(self, a: List[int]) -> List[int]:
        n = len(a)

        ans = [1]*n

        p = 1
        for i in range(n-1):
            p *= a[i]
            a[i+1] *= p

        p = 1
        for i in range(n-1,0,-1):
            p *= a[i]
            a[i-1] *= p

        return a
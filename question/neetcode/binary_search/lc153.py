from typing import List

class Solution:
    def findMin(self, a: List[int]) -> int:
        n = len(a)

        i = n
        ans = -1
        while i >= 1:
            while ans+i<n and a[ans+i] > a[-1]:
                ans+=i
            i//=2

        return a[ans+1]
        
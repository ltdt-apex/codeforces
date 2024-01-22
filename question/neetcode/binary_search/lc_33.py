from typing import List

class Solution:
    def search(self, a: List[int], s: int) -> int:
        n = len(a)

        i = n
        m = -1
        while i>=1:
            while m+i<n and a[m+i] > a[-1]:
                m+=i
            i//=2

        if m == -1:
            l = 0
            r = n
        elif s >= a[0]:
            l = 0
            r = m+1
        else:
            l = m+1
            r = n

        i = n
        while i >= 1:
            while l+i<r and a[l+i] <= s:
                l+=i
            i//=2

        return l if a[l] == s else -1

        
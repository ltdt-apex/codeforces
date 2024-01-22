from typing import List

class Solution:
    def searchMatrix(self, a: List[List[int]], s: int) -> bool:
        n,m = len(a), len(a[0])

        i = n*m
        ans = 0
        while i>=1:
            while ans+i < n*m and a[(ans+i)//m][(ans+i)%m] <= s:
                ans+=i
            i//=2

        return a[ans//m][ans%m] == s
        
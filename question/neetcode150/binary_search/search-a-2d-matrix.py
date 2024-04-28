from typing import List

class Solution:
    def searchMatrix(self, a: List[List[int]], t: int) -> bool:
        n,m = len(a), len(a[0])

        i = 0
        l = n*m

        while l:
            while i+l < n*m and a[(i+l)//m][(i+l)%m] <= t:
                i+=l
            l//=2

        return a[i//m][i%m] == t
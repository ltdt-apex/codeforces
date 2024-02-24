from typing import List
import math

class Solution:
    def minPathSum(self, a: List[List[int]]) -> int:
        n,m = len(a), len(a[0])

        for i in range(n):
            for j in range(m):
                mi = math.inf
                if i > 0:
                    mi = min(mi, a[i-1][j])
                if j > 0:
                    mi  = min(mi, a[i][j-1])

                if mi != math.inf:
                    a[i][j] += mi
        
        return a[-1][-1]

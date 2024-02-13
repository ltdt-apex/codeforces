from typing import List

class Solution:
    def modifiedMatrix(self, a: List[List[int]]) -> List[List[int]]:
        n,m = len(a), len(a[0])
        for j in range(m):
            m = 0
            for i in range(n):
                m = max(m,a[i][j])
            for i in range(n):
                if a[i][j] == -1:
                    a[i][j] = m

        return a
import math
from typing import List

class Solution:
    def maxCoins(self, a: List[int]) -> int:
        n = len(a)+1

        dp = [[-1]*n for _ in range(n)]
        a = [1] + a + [1]

        def dfs(i,j):
            if i == j:
                dp[i][j] = 0
                return dp[i][j]
            if dp[i][j] != -1:
                return dp[i][j]
            
            m = -1
            for k in range(i,j):
                cost = dfs(i,k) + dfs(k+1,j) + a[i]*a[k+1]*a[j+1]
                m = max(m, cost)

            dp[i][j] = m
            return dp[i][j]
        
        return dfs(0,n-1)
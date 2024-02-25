from typing import List
import math

class Solution:
    def minScoreTriangulation(self, a: List[int]) -> int:
        n = len(a)-1

        dp = [[0]*n for _ in range(n)]

        def dfs(i,j):
            if i==j:
                dp[i][j] = 0
                return dp[i][j]
            if dp[i][j]!=0:
                return dp[i][j]
            
            min_ = math.inf
            for k in range(i,j):
                cost = dfs(i,k) + dfs(k+1,j) + a[i]*a[k+1]*a[j+1]
                min_ = min(min_, cost)

            dp[i][j] = min_
            return dp[i][j]
        
        return dfs(0,n-1)

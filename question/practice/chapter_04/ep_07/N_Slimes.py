import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

def solve(test):
    n = int(input())
    a = inputa()

    dp = [[-1]*n for _ in range(n)]
    p = [0] + list(accumulate(a))

    def dfs(i,j):
        # print(i,j)
        if i==j:
            dp[i][j] = 0
            return dp[i][j]
        if dp[i][j] != -1:
            return dp[i][j]
        
        min_ = math.inf
        for k in range(i,j):
            cost = dfs(i,k) + dfs(k+1,j) + p[k+1]-p[i]+p[j+1]-p[k+1]
            min_ = min(min_, cost)
        
        dp[i][j] = min_
        return dp[i][j]
    
    print(dfs(0,n-1))
    # print(dp)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)
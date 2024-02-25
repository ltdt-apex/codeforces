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

    dp = [[(-1,-1)]*n for _ in range(n)]

    def dfs(i,j):
        if i==j:
            dp[i][j] = (a[i], 0)
            return dp[i][j]
        if dp[i][j] != (-1,-1):
            return dp[i][j]
        
        min_ = math.inf
        m = 100

        for k in range(i,j):
            cost = dfs(i,k)[1] + dfs(k+1,j)[1] + dfs(i,k)[0] * dfs(k+1,j)[0]
            r = (dfs(i,k)[0] + dfs(k+1,j)[0]) % 100
            if cost < min_ or cost == min and r < m:
                m = r
                min_ = cost

        dp[i][j] = (m,min_)
        return dp[i][j]
    
    print(dfs(0,n-1)[1])

if __name__ == "__main__":
    while True:
        try:
            solve(1)
        except:
            break
import sys
sys.setrecursionlimit(10**6+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

def solve():
    n = int(input())
    a = [inputa() for _ in range(n)]

    dp = [[-1]*3 for _ in range(n)]

    def dfs(i, j):
        if i < 0:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        
        dp[i][j] = a[i][j] + max(dfs(i-1, (j+1)%3), dfs(i-1, (j+2)%3))
        return dp[i][j]
    
    dfs(n-1,0)
    dfs(n-1,1)
    dfs(n-1,2)

    print(max(dp[-1]))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
import sys
sys.setrecursionlimit(10**5+5)
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
    a = inputa()

    dp = [-1] * n

    def dfs(i):
        if i <= 0:
            return 0
        if i == 1:
            dp[i] = abs(a[1]-a[0])
            return dp[i]
        if dp[i] != -1:
            return dp[i]
        
        dp[i] = min(dfs(i-1) + abs(a[i] - a[i-1]), dfs(i-2) + abs(a[i] - a[i-2]))

        return dp[i]

    dfs(n-1)
    print(dp[-1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
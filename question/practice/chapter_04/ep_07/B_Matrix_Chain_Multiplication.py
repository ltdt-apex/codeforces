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
    a = [inputa() for _ in range(n)]

    a = [a[0][0]] + [x for _,x in a]

    dp = [[0]*(n) for _ in range(n)]

    def dfs(i,j):
        if i == j:
            return 0
        if dp[i][j] != 0:
            return dp[i][j]

        min_ = math.inf
        for k in range(i,j):
            cost = dfs(i,k)+dfs(k+1,j)+a[i]*a[k+1]*a[j+1]
            min_ = min(cost, min_)

        dp[i][j] = min_
        return dp[i][j]

    print(dfs(0,n-1))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)
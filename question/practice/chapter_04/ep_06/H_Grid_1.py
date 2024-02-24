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
    n,m = inputa()
    a = [inputs() for _ in range(n)]

    dp = [[0]*(m+1) for _ in range(n+1)]
    dp[1][1] = 1

    for i in range(1,n+1):
        for j in range(1,m+1):
            if a[i-1][j-1] == "#":
                continue
            dp[i][j] += (dp[i-1][j] + dp[i][j-1])%(10**9+7)

    print(dp[-1][-1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)
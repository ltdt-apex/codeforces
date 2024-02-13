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

def solve():
    while True:
        a = inputs()
        if a == ["#"]:
            return
        b = inputs()

        n,m = len(a), len(b)

        dp = [[0]*(m+1) for _ in range(n+1)]

        for i in range(n+1):
            dp[i][0] = 15 * i
        for j in range(m+1):
            dp[0][j] = 30 * j

        for i in range(1,n+1):
            for j in range(1,m+1):
                if a[i-1] == b[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j] + 15, dp[i][j-1] + 30)

        print(dp[-1][-1])


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
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
    n,m = inputa()
    a = input()
    b = input()

    dp = [[0]*(m+1) for _ in range(n+1)]

    ans = 0
    for i in range(1,n+1):
        for j in range(1,m+1):
            if a[i-1] == b[j-1]:
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2)
            dp[i][j] = max(dp[i][j], dp[i-1][j]-1, dp[i][j-1]-1)
            ans = max(ans, dp[i][j])

    print(ans)
    
if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
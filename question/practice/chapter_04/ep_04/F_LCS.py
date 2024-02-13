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
    a = inputs()
    b = inputs()

    n,m = len(a), len(b)

    dp = [[0]*(m+1) for _ in range(n+1)]

    for i in range(1,n+1):
        for j in range(1,m+1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    k = dp[-1][-1]
    ans = [""]*k

    i = n
    j = m

    while i>0 and j>0:
        if a[i-1] == b[j-1]:
            ans[k-1] = a[i-1]
            i-=1
            j-=1
            k-=1
        else:
            if dp[i-1][j] > dp[i][j-1]:
                i-=1
            else:
                j-=1
    
    print("".join(ans))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
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

    ans = set()

    def dfs(i,j,cur):
        if i==0 or j==0:
            ans.add("".join(cur))
            return
        
        if a[i-1] == b[j-1]:
            cur.append(a[i-1])
            dfs(i-1,j-1,cur)
            cur.pop()
        else:
            if dp[i-1][j] == dp[i][j-1]:
                dfs(i-1,j,cur)
                dfs(i,j-1,cur)
            if dp[i-1][j] < dp[i][j-1]:
                dfs(i,j-1,cur)
            if dp[i-1][j] > dp[i][j-1]:
                dfs(i-1,j,cur)

    dfs(n,m,[])

    for s in ans:
        print(s)



if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1
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
    n,k = inputa()
    a = inputa()

    dp = [-1] * n

    def dfs(i):
        if i <= 0:
            return 0
        if dp[i]!=-1:
            return dp[i]
        
        ans = math.inf
        for j in range(1,k+1):
            t = i-j
            if t < 0:
                break
            ans = min(ans, dfs(t) + abs(a[i] - a[t]))
        dp[i] = ans

        return ans
    
    dfs(n-1)

    print(dp[-1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
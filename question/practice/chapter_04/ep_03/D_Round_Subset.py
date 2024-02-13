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

def find_n2(n):
    ans = 0
    while n%2==0:
        ans+=1
        n//=2
    return ans

def find_n5(n):
    ans = 0
    while n%5==0:
        ans+=1
        n//=5
    return ans

def solve():
    n,l = inputa()
    a = inputa()

    n2 = list(map(find_n2, a))
    n5 = list(map(find_n5, a))

    m = sum(n5)

    dp = [[-math.inf]*(m+1) for _ in range(l+1)]
    dp[0][0] = 0

    for i in range(n):
        for u in range(min(i+1,l),0,-1):
            for j in range(m,-1,-1):
                if j-n5[i]>=0 and u-1>=0:
                    dp[u][j] = max(dp[u][j], dp[u-1][j-n5[i]] + n2[i])
        # print(dp)

    ans = 0
    for j in range(m+1):
        ans=max(ans,min(j,dp[-1][j]))

    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
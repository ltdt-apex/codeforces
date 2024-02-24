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
    # n = int(input())
    s = inputs()
    # print(s)
    n = len(s)
    dp = [0]*n

    j = 0
    for i in range(1,n):
        while j and s[i]!=s[j]:
            j = dp[j-1]
        if s[i] == s[j]:
            j+=1
        dp[i]=j
    # print(dp)

    # for i in range(n-1,-1,-1):
    #     j = i + 1 - dp[i]
    #     # print(i, j)
    #     if (i+1)%2 == 0 and ((i+1)//2)%j == 0:
    #         k = (i+1)//2
    #         st = n-i-1
    #         # print(k,st)
    #         ans = ""
    #         for l in range(8):
    #             ans += s[(l+st)%k]
    #         ans+="..."
    #         print(ans)
    #         break
        
    j = n - dp[-1]
    k = n%j

    # print(j,k)

    ans = ""

    for i in range(8):
        ans+=s[(i+k)%j]

    ans += "..."
    print(ans)

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        test-=1
        solve(test)
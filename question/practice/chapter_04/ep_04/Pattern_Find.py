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
    s = input()
    n,k = s.strip().split()

    k1 = len(k)

    n = list(n)
    k = list(k)

    k+=["#"]
    k+=n

    ans = []
    dp = [0]*len(k)
    for i in range(1,len(k)):
        j = dp[i-1]
        while j > 0 and k[j] != k[i]:
            j = dp[j-1]
        if k[j]==k[i]:
            j+=1
        dp[i] = j
        if dp[i] == k1:
            ans.append(i-k1-1+1-k1+1)


    # dpn = [0]*len(n)
    # for i in range(len(n)):
    #     if i==0:
    #         j=0
    #     else:
    #         j = dpn[i-1]
    #     while j>0 and k[j]!=n[i]:
    #         j=dp[j-1]
    #     if k[j]==n[i]:
    #         j+=1
    #     dpn[i] = j
    #     if dpn[i]==len(k)-1:
    #         ans.append(i+1-len(k)+2)

    if ans:
        print(len(ans))
        print(*ans)
    else:
        print("Not Found")

    print()

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1
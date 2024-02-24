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
    a = inputs()
    w = inputs()
    s = inputs()

    ans = []
    d = {c:i for i,c in enumerate(a)}
    d["#"] = len(a)
    # print(d)

    n = len(a)

    w += "#"
    dp = [0]*(len(w))
    for i in range(1,len(w)):
        j = dp[i-1]
        while j and w[j] != w[i]:
            j = dp[j-1]
        if w[j] == w[i]:
            j+=1
        dp[i] = j

    ddp = [[0]*(n+1) for _ in range(len(w))]
    for i in range(len(w)):
        for j in range(len(a)+1):
            if i and j!=d[w[i]]:
                ddp[i][j] = ddp[dp[i-1]][j]
            else:
                ddp[i][j] = i + int(j == d[w[i]])

    # print(ddp)

    for k in range(n):
        j = 0
        count = 0
        for i in range(len(s)):
            # while j and d[w[j]] != (d[s[i]]-k)%len(a):
            #     j = dp[j-1]
            # if d[w[j]] == (d[s[i]]-k)%len(a):
            #     j+=1

            j = ddp[j][(d[s[i]]-k)%len(a)]
            if j == len(w)-1:
                count+=1
        
        if count == 1:
            ans.append(k)

    if not ans:
        print("no solution")
    elif len(ans) == 1:
        print("unique:", *ans)
    else:
        print("ambiguous:", *ans)


if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        test-=1
        solve(test)
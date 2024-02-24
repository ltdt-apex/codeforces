import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math
import bisect

def inputa():
    return input().split()

def inputs():
    return list(input().strip())

def solve(test):
    n,m = list(map(int ,input().split()))

    a = [inputa() for _ in range(n)]

    for i in range(n):
        a[i][0] = int(a[i][0])
        a[i][1] = float(a[i][1])

    a.sort()

    dp = []

    for _,x in a:
        i = bisect.bisect_left(dp, x)

        if i == len(dp):
            dp.append(x)
        else:
            dp[i] = x

    print(n - len(dp))
        

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)
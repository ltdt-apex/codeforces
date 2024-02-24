import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math
import bisect

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

def solve(test):
    n,m,l = inputa()
    a = inputa()
    b = inputa()
    c = inputa()

    a.sort()
    b.sort()
    c.sort()

    a += b
    a += c

    dp = []

    for x in a:
        i = bisect.bisect_left(dp,x)
        if i == len(dp):
            dp.append(x)
        else:
            dp[i] = x

    print(len(a) - len(dp))


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)
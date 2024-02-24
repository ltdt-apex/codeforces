import bisect
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
    n = int(input())
    a = inputa()

    dp = []

    a = [x-i-1 for i,x in enumerate(a)]

    for x in a:
        if x>=0:
            i = bisect.bisect_right(dp,x)
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
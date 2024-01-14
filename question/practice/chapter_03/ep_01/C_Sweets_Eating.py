import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,m = inputa()
    a = inputa()

    a.sort()

    dp = [0]*m
    ans = 0
    for i in range(n):
        ans += a[i]
        ans += dp[i%m]
        dp[i%m] += a[i]
        print(ans, end=" ")


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
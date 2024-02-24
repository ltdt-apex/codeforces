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

    dp = [1]*n

    for i in range(n):
        for j in range(i):
            if abs(a[i]) > abs(a[j]) and (a[i]<0) == (a[j]>0):
                dp[i] = max(dp[i], dp[j]+1)
                
    print(max(dp))


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)
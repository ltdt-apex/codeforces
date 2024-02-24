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
    input()
    a = inputs()
    n = len(a)
    dp = [0]*n

    for i in range(1,n):
        j = dp[i-1]
        while j and a[j] != a[i]:
            j = dp[j-1]
        if a[j] == a[i]:
            j+=1
        dp[i] = j

    # print(dp)
    if n%(n-dp[-1]) == 0:
        print(n-dp[-1])
    else:
        print(n)

    if test:
        print()

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        test-=1
        solve(test)
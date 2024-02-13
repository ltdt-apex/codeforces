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
    k,n = inputa()
    a = [inputa() for _ in range(k)]

    ans = [0]*(n+1)

    for (w,v) in a:
        for j in range(n,-1,-1):
            if j - w >= 0:
                ans[j] = max(ans[j], ans[j-w]+v)

    print(max(ans))


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
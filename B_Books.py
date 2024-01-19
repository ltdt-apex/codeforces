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
    n, t = inputa()
    a = inputa()

    l = 0
    ans = 0
    total = 0
    for r in range(n):
        total += a[r]
        while total > t:
            total -= a[l]
            l+=1
        ans = max(ans, r-l+1)

    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
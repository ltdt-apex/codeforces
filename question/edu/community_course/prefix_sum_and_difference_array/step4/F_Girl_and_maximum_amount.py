import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n, k = inputa()
    a = inputa()

    ks = [inputa() for _ in range(k)]

    ap = [0]*(n)

    for l,r in ks:
        l-=1
        ap[l] += 1
        if r < n:
            ap[r] -= 1

    ap = list(accumulate(ap))

    ap.sort()
    a.sort()

    print(sum(i*j for i,j in zip(a, ap)))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
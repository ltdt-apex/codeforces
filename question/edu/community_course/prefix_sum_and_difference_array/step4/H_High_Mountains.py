import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n = int(input())
    a = inputa()

    q = int(input())
    qs = [inputa() for i in range(q)]

    ap = [0]*n
    for l, h in qs:
        ap[-l] += h

    ap = list(accumulate(ap))

    for i in range(n):
        a[i] += ap[i]

    print(*a)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
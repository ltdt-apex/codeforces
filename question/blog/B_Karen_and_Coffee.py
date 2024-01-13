import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,k,q = inputa()

    ns = [inputa() for i in range(n)]
    qs = [inputa() for i in range(q)]

    ap = [0] * 200002
    for l,r in ns:
        ap[l] += 1
        ap[r+1] -= 1

    ap = list(accumulate(ap))
    ap = [1 if l >= k else 0 for l in ap]
    ap = list(accumulate(ap))

    for l,r in qs:
        print(ap[r] - ap[l-1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
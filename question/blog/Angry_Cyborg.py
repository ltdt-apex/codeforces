import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,q = inputa()
    qs = [inputa() for i in range(q)]

    a = [0] * n
    for l,r in qs:
        l-=1
        a[l] += 1
        if r < n:
            a[r] -= 1

    a = list(accumulate(a))

    for l, r in qs:
        if r < n:
            a[r] -= r-l+1
            
    a = list(accumulate(a))

    print(*a)



if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1
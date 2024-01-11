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
    a = [[int(c) for c in input().strip()] for i in range(n)]

    q = int(input())
    qs = [inputa() for i in range(q)]

    ap = [[0]*n for i in range(m)]

    for t,l,d,r in qs:
        t-=1
        l-=1
        ap[t][l] += 1
        if r < m:
            ap[t][r]-=1
        if d < n:
            ap[d][l]-=1
        if d < n and r < m:
            ap[d][r] += 1
    
    ap = list(zip(*map(accumulate, zip(*map(accumulate, ap)))))
    
    for i in range(n):
        for j in range(m):
            a[i][j] = (a[i][j] + ap[i][j])%2
            print(a[i][j], end="")
        print()

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
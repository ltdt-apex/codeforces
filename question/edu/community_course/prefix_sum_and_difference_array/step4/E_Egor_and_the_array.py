import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,m,k = inputa()
    a = inputa()
    
    ms = [inputa() for i in range(m)]
    ks = [inputa() for i in range(k)]

    mp = [0]*(m+1)
    for l,r in ks:
        l-=1
        mp[l] += 1
        mp[r] -= 1

    mp = list(accumulate(mp))

    ap = [0]*(n+1)
    for i, (l,r,d) in enumerate(ms):
        l-=1
        ap[l] += d*mp[i]
        ap[r] -= d*mp[i]

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
import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def solve():
    n,m,k = list(map(int, input().split()))
    a = list(map(int, input().split()))

    ms = [list(map(int, input().split())) for i in range(m)]
    ks = [list(map(int, input().split())) for j in range(k)]

    mp = [0]*m

    for l,r in ks:
        l-=1
        mp[l] += 1
        if r < m:
            mp[r] -= 1
    
    mp = list(accumulate(mp))

    ap = [0]*n

    for i, (l,r,d) in enumerate(ms):
        l-=1
        ap[l] += d * mp[i]
        if r < n:
            ap[r] -= d * mp[i]

    ap = list(accumulate(ap))

    a = [i+j for i,j in zip(a, ap)]

    print(*a)
    


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1
import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,m,c = inputa()
    a = inputa()
    ms = inputa()

    mp = [0] * n
    for i in range(m):
        mp[i] += ms[i]
        if i + n-m+1 < n:
            mp[i+n-m+1] -= ms[i]

    mp = list(accumulate(mp))

    a = [(i+j)%c for i, j in zip(a,mp)]
    print(*a)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1